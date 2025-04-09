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
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<31);
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

vector<int> factorlg(int _n){
    vector<int> spf;
    while(smallest_factor[_n]){
        spf.push_back(smallest_factor[_n]);
        _n /= smallest_factor[_n];
    }
    sort(all(spf));
    return spf;
}

vector<int> factor(ll _n){
    vector<int> spf;
    for (int i = 2; 1LL * i * i <= _n; i++)
        while(_n % i == 0)
            spf.push_back(i), _n /= i;
    if (_n != 1)
        spf.push_back(_n);
    sort(all(spf));
    return spf;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    int N = 1e7+100;
    sieve(N);
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), pa, pb;
    getv(a);
    getv(b);
    int ans = 0;
    for (int i = 0; i<n; i++) {
        pa = factor(a[i]);
        pb = factor(b[i]);
        while(pa.size() && pb.size() && pa.back() == pb.back())
            pa.pop_back(), pb.pop_back();
        ans += pa.size() + pb.size();
    }
    cout << ans;
}