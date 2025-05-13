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
int dp[501][501];
int rec(int l, int w) {
    if (l == w)
        return 0;
    if (l == 1)
        return w-1;
    if (w == 1)
        return l-1;
    if (l < w)
        swap(l, w);
    int& ret = dp[l][w];
    if (~ret)
        return ret;
    ret = 1e9;
    for (int i = 1; i < l; i++)
        chmin(ret, rec(i, w) + rec(l-i, w) + 1);
    for (int i = 1; i < w; i++)
        chmin(ret, rec(l, i) + rec(l, w-i) + 1);
    return ret;
}
void solve() {
    int a, b; 
    for (int i = 0; i<=500; i++)
        for (int j = 0; j<=500; j++)
            dp[i][j] = ((i != j) * 1e9);
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int l = 1; l < i; l++) 
                chmin(dp[i][j], dp[l][j] + dp[i-l][j] + 1);
            for (int w = 1; w < j; w++)
                chmin(dp[i][j], dp[i][w] + dp[i][j-w] + 1);
        }
    }
    cout << dp[a][b];
}