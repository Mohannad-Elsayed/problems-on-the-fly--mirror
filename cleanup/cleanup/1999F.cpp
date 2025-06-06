#define ONLINE_JUDGE
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

namespace combinatorics {
    ll MOD;
    vector<ll> fac, inv, finv;
    ll nCr(ll x, ll y) {
        if (x < 0 || y > x || y < 0) return (0);
        return (fac[x] * finv[y] % MOD * finv[x - y] % MOD);
    }
    ll nPr(ll x, ll y) {
        if (x < 0 || y > x || y < 0) return 0;
        return fac[x] * finv[x - y] % MOD;
    }
    ll power(ll b, ll n) {
        b %= MOD;
        ll s = 1;
        while (n) {
            if (n & 1) s = s * b % MOD;
            b = b * b % MOD;
            n /= 2;
        }
        return s;
    }
    void init(int n, ll mod) {
        fac.resize(n + 1);
        inv.resize(n + 1);
        finv.resize(n + 1);
        MOD = mod;
        fac[0] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
        for (ll i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
        for (ll i = 2; i <= n; ++i) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        for (ll i = 2; i <= n; ++i) finv[i] = finv[i - 1] * inv[i] % MOD;
    }
    ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
    ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
    ll sub(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }
    ll divide(ll a, ll b) { return mul(a, power(b, MOD - 2)); }
    ll Inv(int x) { return power(x, MOD - 2); }
    ll catalan(int n) { return (nCr(2 * n, n) * Inv(n + 1)) % MOD; }
    ll StarsAndPars(ll n, ll k) { return nCr(n + k - 1, k - 1); }
};  // namespace combinatorics
// using namespace combinatorics;

ll mod = int(1e9) + 7;
int N = int(2e5+100);
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    combinatorics::init(N, mod);
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, k; cin >> n >> k;
    int t, ones = 0, zeros = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
        cin >> t, (t ? ones++ : zeros++);
    
    int lo = (k+1)>>1;
    
    for (int i = lo; i <= k; i++) {
        print(ones, zeros, i);
        print(combinatorics::nCr(ones, i));
        print(combinatorics::nCr(zeros, k-i));
        ans = combinatorics::add(
                ans,
                combinatorics::mul(
                    combinatorics::nCr(ones, i), 
                    combinatorics::nCr(zeros, k-i)
                )
            );  
    }

    cout << ans;
    
}