#include <bits/stdc++.h>
#include <cuda_runtime.h>
using namespace std;
using ll = long long;
ll MOD = (ll)1e9 + 7;

__device__ ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

__device__ ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

__global__ void computeLCM(int *v, int n, ll *results, ll MOD) {
    int i = blockIdx.x;
    int j = threadIdx.x;

    if (i < n && j < n && i < j) {
        ll gccd = gcd(v[i], v[j]);
        results[i * n + j] = lcm(1, gccd) % MOD;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    // Allocate memory on the device
    int *d_v;
    ll *d_results;
    cudaMalloc(&d_v, n * sizeof(int));
    cudaMalloc(&d_results, n * n * sizeof(ll));

    // Copy data to the device
    cudaMemcpy(d_v, v.data(), n * sizeof(int), cudaMemcpyHostToDevice);

    // Launch the kernel
    dim3 blocks(n);
    dim3 threads(n);
    computeLCM<<<blocks, threads>>>(d_v, n, d_results, MOD);

    // Copy results back to the host
    vector<ll> results(n * n, 0);
    cudaMemcpy(results.data(), d_results, n * n * sizeof(ll), cudaMemcpyDeviceToHost);

    // Compute the final result
    ll lccm = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            lccm = (lccm * results[i * n + j]) % MOD;
        }
    }

    cout << lccm;

    // Free device memory
    cudaFree(d_v);
    cudaFree(d_results);

    return 0;
}