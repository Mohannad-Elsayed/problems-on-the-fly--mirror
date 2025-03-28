#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <fstream>  // For ofstream
#include <algorithm> // For min
#include <iostream>
#include <vector>

using ll = long long;

// Device function for GCD calculation
__device__ int device_gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Device function for LCM calculation
__device__ int device_lcm(int a, int b) {
    int gcd = device_gcd(a, b);
    return (a / gcd) * b; // Safe division first to prevent overflow
}

// Device function to check if number is prime
__device__ bool device_isPrime(long long n) {
    if (n <= 1)
        return false;
    
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i = 0; i < 10; i++) {
        if (n == primes[i])
            return true;
        if (n % primes[i] == 0)
            return false;
    }
    
    int arr[] = {1, 7, 11, 13, 17, 19, 23, 29};
    // 30k + 1, 30k + 7
    for (long long i = 30; i * i <= n; i += 30)
        for (int j = 0; j < 8; j++)
            if (n % (i+arr[j]) == 0)
                return false;

    return true;
}

// Host function to check if number is prime
bool isPrime(ll n) {
    if (n <= 1)
        return false;
    
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int primesc = sizeof(primes) / sizeof(primes[0]);
    for (int i = 0; i<primesc; i++) {
        if (n == primes[i])
            return true;
        if (n % primes[i] == 0)
            return false;
    }
    
    int arr[] = {1, 7, 11, 13, 17, 19, 23, 29};
    int arrc = sizeof(arr)/sizeof(arr[0]);
    // 30k + 1, 30k + 7
    for (ll i = 30; i * i <= n; i += 30)
        for (int j = 0; j < arrc; j++)
            if (n % (i+arr[j]) == 0)
                return false;

    return true;
}

// CUDA kernel for computing prime check on LCM/GCD
__global__ void countPrimesKernel(int n, int* count) {
    int a = blockIdx.x + 1;
    int b = threadIdx.x + a + 1;
    
    if (a <= n && b <= n) {
        int g = device_gcd(a, b);
        int l = (a / g) * b; // Calculate LCM more safely
        if (device_isPrime(l / g)) {
            atomicAdd(count, 1);
        }
    }
}

// Helper function to check CUDA errors
void checkCudaError(cudaError_t err, const char* msg) {
    if (err != cudaSuccess) {
        fprintf(stderr, "CUDA Error: %s (%s)\n", msg, cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
}

void stress() {
    const int MAX_N = 10000; // Reduced for testing
    std::vector<int> res(MAX_N + 1);
    int* d_count;
    
    cudaError_t err = cudaMalloc(&d_count, sizeof(int));
    checkCudaError(err, "Failed to allocate device memory");
    
    for (int n = 1; n <= MAX_N; n++) {
        // Reset counter to 0
        int host_count = 0;
        err = cudaMemcpy(d_count, &host_count, sizeof(int), cudaMemcpyHostToDevice);
        checkCudaError(err, "Failed to copy count to device");
        
        // Launch kernel with appropriate dimensions
        int threadsPerBlock = std::min(n, 1024);
        int numBlocks = n;
        countPrimesKernel<<<numBlocks, threadsPerBlock>>>(n, d_count);
        
        // Check for kernel launch errors
        err = cudaGetLastError();
        checkCudaError(err, "Kernel launch failed");
        
        // Synchronize before copying results back
        err = cudaDeviceSynchronize();
        checkCudaError(err, "Kernel execution failed");
        
        // Copy result back
        err = cudaMemcpy(&host_count, d_count, sizeof(int), cudaMemcpyDeviceToHost);
        checkCudaError(err, "Failed to copy count from device");
        
        res[n] = host_count;
        
        if (n % 1000 == 0) {
            std::cout << "Completed n = " << n << ", count = " << host_count << std::endl;
        }
    }
    
    cudaFree(d_count);
    
    // Print or save results
    std::ofstream outfile("results.txt");
    if (!outfile.is_open()) {
        std::cerr << "Failed to open output file" << std::endl;
        return;
    }
    for (int i = 1; i <= MAX_N; i++) {
        outfile << i << " " << res[i] << std::endl;
    }
    outfile.close();
}

int main() {
    // Initialize CUDA
    cudaError_t err = cudaSetDevice(0);
    checkCudaError(err, "Failed to set CUDA device");
    
    stress();
    return 0;
}