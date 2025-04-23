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
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

ll bin_pow(ll base, ll power, ll mod = (ll)1e9+7) {
    base %= mod;
    ll ans = 1;
    while (power > 0) {
        if (power & 1) ans = ans * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return ans;
}
ll fp(ll b, ll n, ll MOD = (ll)1e9+7) {
    b %= MOD;
    ll s = 1;
    while (n) {
        if (n & 1) s = s * b % MOD;
        b = b * b % MOD;
        n >>= 1;
    }
    return s;
}
void solve() {
    print(fp(ll(1e15), 10000));
    print(bin_pow(ll(1e15), 10000));
}