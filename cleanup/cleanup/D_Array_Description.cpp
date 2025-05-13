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
    // freopen("area.in", "r", stdin);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int n, m, mod = 1e9+7;
vector<int> arr;
vector<vector<int>> dp;
int rec(int idx, int le) { // last element 
    if (idx == n) {
        return 1;
    }
    int& ret = dp[idx][le];
    if (~ret) {
        return ret;
    }
    ret = 0;
    if (arr[idx] == 0) {
        if (idx == 0) {
            for (int i = 1; i <= m; i++) {
                ret += rec(idx+1, i);
                ret %= mod;
            }
        } else {
            if (le-1 > 0)
                ret += rec(idx+1, le-1);
            ret %= mod;
            ret += rec(idx+1, le);
            ret %= mod;
            if (le+1 <= m)
                ret += rec(idx+1, le+1);
            ret %= mod;
        }
    } else {
        if (idx == 0 || abs(arr[idx]-le) <= 1)
            ret += rec(idx+1, arr[idx]);
        ret %= mod;
    }
    return ret%mod;
}
void solve() {
    cin >> n >> m;
    arr = vector<int>(n);
    dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
    getv(arr);
    cout << rec(0, 0);
}