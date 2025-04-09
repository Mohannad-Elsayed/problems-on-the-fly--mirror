#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << x, 0;
#define killn(x) return cout << x << '\n', 0;

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #pragma GCC optimize("O3,unroll-loops,Ofast")
    // #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

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
using namespace combinatorics;


int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    pre(); 
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    init((int)1e5 + 10, (ll)1e9+7);

    //________________________
    return 0;
}
int solve(){
    int n; cin >> n;
    vector<ll> v(n);
    each(i, v)
        cin >> i;
    
    ll m = (n % 2 ? 1 : -1), ans = 0;
    for (int i = 0; i<n; i++){
        ans = add(ans, m * mul(nCr(n-1, i), v[i]));
        m *= -1;
    }
    cout << sub(ans, 0ll);
    //________________________
    return 0;
}