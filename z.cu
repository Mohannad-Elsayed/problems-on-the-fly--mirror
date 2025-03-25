#include <iostream>
#include <vector>
#include <numeric> // For gcd
#include <algorithm> // For lcm
#include <cuda_runtime.h>

// Custom atomicAdd for long long
__device__ long long atomicAddLongLong(long long* address, long long val) {
    unsigned long long int* address_as_ull = (unsigned long long int*)address;
    unsigned long long int old = *address_as_ull, assumed;
    do {
        assumed = old;
        old = atomicCAS(address_as_ull, assumed, val + assumed);
    } while (assumed != old);
    return old;
}

using namespace std;
using ll = long long;
const int MOD = 1000000007; // Fixed 1e9 + 7 to explicit integer value

// Helper function to compute gcd (needed for device code)
__device__ __host__ ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// CUDA kernel to compute gcd and lcm in parallel
__global__ void computeLcmKernel(int* v, int n, ll* result) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;

    if (i < n && j < n && i < j) {
        ll gcd_val = gcd(v[i], v[j]);
        ll lcm_val = (v[i] / gcd_val) * v[j];
        atomicAddLongLong(result, lcm_val % MOD);
        // atomicAdd(result, lcm_val % MOD);
    }
}

// Host function
void stress() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Allocate memory on the device
    int* d_v;
    ll* d_result;
    ll h_result = 0;

    cudaMalloc(&d_v, n * sizeof(int));
    cudaMalloc(&d_result, sizeof(ll));
    cudaMemcpy(d_v, v.data(), n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_result, &h_result, sizeof(ll), cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 blockDim(16, 16);
    dim3 gridDim((n + blockDim.x - 1) / blockDim.x, (n + blockDim.y - 1) / blockDim.y);

    // Launch the kernel
    computeLcmKernel<<<gridDim, blockDim>>>(d_v, n, d_result);

    // Copy the result back to the host
    cudaMemcpy(&h_result, d_result, sizeof(ll), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_v);
    cudaFree(d_result);

    // Output the result
    cout << h_result % MOD << endl;
}

// Added main function to call stress
int main() {
    stress();
    return 0;
}