#define ONLINE_JUDGE
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
#define int ll
void solve() {
    int n, w; cin >> n >> w;

    vector<int> wei(n+1), prof(n+1);
    for (int i = 1; i <= n; i++) 
        cin >> wei[i] >> prof[i];
    print(wei, prof);
    vector<vector<int>> dp(n+1, vector<int>(w+1));
    for (int i = 0; i <= n; i++) {
        for (int we = 0; we <= w; we++) {
            if (!i || !we) {
                dp[i][we] = 0;
                continue;
            }
            if (we >= wei[i]) { // TODO change to '>' only
                dp[i][we] = max(
                    dp[i-1][we], /* leave */
                    dp[i-1][we-wei[i]] + prof[i] /* take */
                );
            } else dp[i][we] = dp[i-1][we];
        }
        // each(vv, dp) {
        //     each(i, vv)
        //         cout << i << ' ';
        //     cout << "\n";
        // } cout << "\n\n";
    }
    cout << dp[n][w];
}