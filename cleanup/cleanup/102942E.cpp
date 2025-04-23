// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
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
int rnglr(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
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
void stress() {
    int cnt = 0;
    char fin = '8';
    for (int i = '3'; i <= fin; i++) 
        for (int j = i; j <= fin; j++) 
            for (int k = j; k <= fin; k++)
                for (int l = k; l <= fin; l++) {
                    string s; 
                    s.push_back(i);
                    s.push_back(j);
                    s.push_back(k);
                    s.push_back(l);
                    cout << s << '\n';
                    cnt++;
                }
    print(cnt);
    // - - - - 
    // 3 4 5 6 7 8 => 6 values
    exit(0);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    combinatorics::init(int(1e5+100), int(1e9+7));
    // stress();
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n; cin >> n;
    string s, ss; cin >> s;
    each(ch, s)
        if (ch != '-')
            ss.push_back(ch);
    // print(ss);
    if (!is_sorted(all(ss)))
        kill(0);
    
    s.insert(s.begin(), '1');
    s.push_back('9');
    print(s);
    vector<pair<int, int>> vp; // curr digit, index
    for (int i = 0; i<=n+1; i++) {
        if (s[i] != '-') {
            vp.emplace_back(s[i]-'0', i);
        }
    }
    print(vp);
    ll ans = 1;
    for (int i = 1; i < vp.size(); i++) {
        int len = vp[i].second - vp[i-1].second-1;
        int digits = vp[i].first - vp[i-1].first+1;
        print(len, digits);
        ans = combinatorics::mul(ans, combinatorics::StarsAndPars(len, digits));
    }
    cout << ans;

}