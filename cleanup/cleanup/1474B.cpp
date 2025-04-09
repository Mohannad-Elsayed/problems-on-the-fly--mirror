// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
void solve();
int N = 1e6+100;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

map<int, int> factor(int _n){
    map<int, int> fac;
    assert(_n >= 2 && "Number must be > 2 to factorize!");
    while(smallest_factor[_n]){
        fac[smallest_factor[_n]]++;
        _n /= smallest_factor[_n];
    }
    return fac;
}

map<ll, int> factor(ll _n){
    map<ll, int> fac;
    assert(_n >= 2 && "Number must be > 2 to factorize!");
    for (int i = 0; (ll)primes[i] * primes[i] <= _n; i++)
        while(_n % primes[i] == 0)
            fac[primes[i]]++, _n /= primes[i];
    if (_n != 1)
        fac[_n]++;
    return fac;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    sieve(N);
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

ll next_prime(ll a){
    for (ll i = a; ; i++)
        if (prime[i])
            return i;
}
void solve(){
    ll n; cin >> n;
    ll n1 = next_prime(1+n);
    ll n2 = next_prime(n1+n);
    print(n);
    print(n1);
    print(n2);
    cout << n1 * n2;
}