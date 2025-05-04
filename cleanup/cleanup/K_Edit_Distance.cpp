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

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for (int i = n; ~i; i--) 
        dp[i][m] = a.size() - i;
    for (int i = m; ~i; i--) 
        dp[n][i] = b.size() - i;
    for (int i = n-1; ~i; i--) {
        for (int j = m-1; ~j; j--) {
            if (a[i] == b[j])
                dp[i][j] = dp[i+1][j+1];
            else
                dp[i][j] = min({
                    dp[i+1][j],
                    dp[i][j+1],
                    dp[i+1][j+1]
                }) + 1;
        }
    }
    // for (int i = 0; i<=n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }cout << '\n';
    // }
    cout << dp[0][0];
}