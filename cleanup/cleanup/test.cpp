#include <bits/stdc++.h>
#include <omp.h>  // OpenMP header

using namespace std;

int main() {
    long long n = 1e12; // Large workload to test CPU usage
    long long sum = 0;

    #pragma omp parallel for reduction(+:sum) num_threads(12) // Utilize all CPU threads
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
