#define ONLINE_JUDGE
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    combinatorics::init(2000, ll(1e9+7));
    // cout << combinatorics::nCr(1000, 2);
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}


// lol? https://www.geeksforgeeks.org/pairs-with-same-manhattan-and-euclidean-distance/
void solve(){
    ll k; 
    cin >> k;
    if (!k)
        kill(k);
    
    int y = 0, pairs = 0, rnd = 100;
    vector<pair<int, int>> ans;
    while (pairs < k){
        int cnt = 0;
        for (int i = 1; i <= 500; i++){
            if (pairs + cnt <= k){
                ans.push_back({y, (i * rnd)});
                pairs += cnt++;
            }
        }
        y+=cnt, rnd++;
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        cout << x << ' ' << y << '\n';
}