// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
void solve();

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

map<int, int> factorlg(int _n){
    map<int, int> fac;
    while(smallest_factor[_n]){
        fac[smallest_factor[_n]]++;
        _n /= smallest_factor[_n];
    }
    return fac;
}

map<ll, int> factor(ll _n){
    map<ll, int> fac;
    for (int i = 0; (ll)primes[i] * primes[i] <= _n; i++)
        while(_n % primes[i] == 0)
            fac[primes[i]]++, _n /= primes[i];
    if (_n != 1)
        fac[_n]++;
    return fac;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    int N = 1e5;
    sieve(N);
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int a, b, k; cin >> a >> b >> k;
    if (k == 1){
        if (a%b && b%a)
            kill("NO");
        if (a == b)
            kill("NO");
        kill("YES");
    }
    int cnt = 0;
    for (auto [x, y] : factor(a))
        cnt += y;
    for (auto [x, y] : factor(b))
        cnt += y;
    print(cnt, k);
    if (k > cnt)
        kill("NO");
    kill("YES");
    
}