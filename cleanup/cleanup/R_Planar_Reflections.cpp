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
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
constexpr int N = 1010, mod = 1e9+7;
int dp[N][N][2];
int n, k;
int rec(int rem, int idx, int dir) {
    if (idx < 0 || idx == n)
        return 1;
    int& ret = dp[rem][idx][dir];
    if (~ret)
        return ret;
    ret = 0;
    if (dir) {
        if (rem > 1)
            ret += rec(rem-1, idx-1, !dir); ret %= mod;
        ret += rec(rem, idx+1, dir); ret %= mod;
    } else {
        ret += rec(rem, idx-1, dir); ret %= mod;
        if (rem > 1)
            ret += rec(rem-1, idx+1, !dir); ret %= mod;
    }
    return ret;
}
void solve() {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    int res = rec(k, 0, 1);
    cout << res;
}