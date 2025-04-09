#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    if(limit >= 0) isPrime[0] = false;
    if(limit >= 1) isPrime[1] = false;
    for (int i = 2; i * i <= limit; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
    return isPrime;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Sieve for primes up to n
    vector<bool> isPrimeN = sieve(n);
    
    // Build prefix sum: prefix[i] = number of primes in [1, i]
    vector<int> prefix(n+1, 0);
    for (int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + (isPrimeN[i] ? 1 : 0);
    }
    
    int m = prefix[n]; // total number of primes in [1,n]
    vector<long long> freq(m+1, 0);
    for (int i = 0; i <= n; i++){
        freq[prefix[i]]++;
    }
    
    // Sieve for primes up to m (for possible range differences)
    vector<bool> isPrimeDiff = sieve(m);
    
    // Count valid intervals where the difference in prefix sums is prime
    long long ans = 0;
    for (int diff = 2; diff <= m; diff++){
        if(isPrimeDiff[diff]){
            for (int x = 0; x <= m - diff; x++){
                ans += (long long)freq[x] * freq[x+diff];
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
