#include <cuda_runtime.h>
#include <iostream>
using namespace std;

using ll = long long;
#define int ll
const int MOD = (int)1e9 + 7;

//---------------------------------------------------------
// Device function: count1
//---------------------------------------------------------
__device__ ll d_count1(ll X, int k) {
    if (X < 0) return 0;
    ll cycle = 1LL << (k + 1);
    ll half = 1LL << k;
    ll full = (X + 1) / cycle;
    ll res = full * half;
    ll rem = (X + 1) % cycle;
    res += (rem > half ? rem - half : 0);
    return res;
}

//---------------------------------------------------------
// Kernel for optimized o(n) (computed by a single thread)
//---------------------------------------------------------
__global__ void o_kernel(int n, int *d_result) {
    if (threadIdx.x == 0 && blockIdx.x == 0) {
        ll ans = 0;
        ll ones_cache[64];
        for (int i = 0; i < 64; i++)
            ones_cache[i] = -1;
        for (int k = 0; (1LL << k) <= n; k++) {
            ll p = 1LL << k;
            ll totalCount = (n - p + 1);
            ll ones = (ones_cache[k] == -1 ? d_count1(n - p, k) : ones_cache[k]);
            ones_cache[k] = ones;
            ll count0 = totalCount - ones;
            ll onesAll = d_count1(n, k);
            ans = (ans + count0 + onesAll) % MOD;
        }
        *d_result = ans % MOD;
    }
}

//---------------------------------------------------------
// Kernel for brute-force b(n)
// Each thread computes one (i,j) pair.
//---------------------------------------------------------
__global__ void b_kernel(int n, int *d_result) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    int local = 0;
    if (i <= n && j <= n) {
        if (__popc(i ^ j) == 1) {
            local = 1;
        }
    }
    // Fix: Use atomicAdd with `unsigned long long`
    if (local)
        atomicAdd((unsigned long long*)d_result, (unsigned long long)local);
}

//---------------------------------------------------------
// Host wrapper: Compute b(n) on GPU
//---------------------------------------------------------
int b_gpu(int n) {
    int h_result = 0;
    int *d_result;
    cudaMalloc(&d_result, sizeof(int));
    cudaMemcpy(d_result, &h_result, sizeof(int), cudaMemcpyHostToDevice);

    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((n + threadsPerBlock.x) / threadsPerBlock.x,
                   (n + threadsPerBlock.y) / threadsPerBlock.y);
    b_kernel<<<numBlocks, threadsPerBlock>>>(n, d_result);
    cudaDeviceSynchronize();
    cudaMemcpy(&h_result, d_result, sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_result);
    return h_result % MOD;
}

//---------------------------------------------------------
// Host wrapper: Compute o(n) on GPU
//---------------------------------------------------------
int o_gpu(int n) {
    int h_result = 0;
    int *d_result;
    cudaMalloc(&d_result, sizeof(int));
    cudaMemcpy(d_result, &h_result, sizeof(int), cudaMemcpyHostToDevice);

    o_kernel<<<1, 1>>>(n, d_result);
    cudaDeviceSynchronize();
    cudaMemcpy(&h_result, d_result, sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_result);
    return h_result % MOD;
}

//---------------------------------------------------------
// Main: test for n from 0 to 9999
//---------------------------------------------------------
signed main() {
    // for (int n = 0; n <= 1000000; n++) {
    //     int res_o = o_gpu(n);
    //     int res_b = b_gpu(n);
    //     if (res_o != res_b) {
    //         cout << "Mismatch at n = " << n << ": o(n) = " << res_o << " vs b(n) = " << res_b << "\n";
    //         return 0;
    //     }
    //     cout << n << ' ';
    // }
    // cout << "\nAll Passed!";
    // cout << b_gpu(1000000);
    return 0;
}
