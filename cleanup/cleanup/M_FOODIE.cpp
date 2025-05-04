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
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n+1), dp(k+1);
    // vector<vector<int>> dp(n+1, vector<int>(k+1));
    for (int i = 1; i <= n; i++) {
        int sum = 0, t, x;
        cin >> t;
        while(t--) {
            cin >> x;
            sum += x;
        }
        v[i] = sum;
    }
    // print(v);
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= k; j++) {
    //         if (j >= v[i])
    //             dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]] + v[i]);
    //         else dp[i][j] = dp[i-1][j];
    //     }
    // }
    for (int i = 1; i <= n; i++)
        for (int j = k; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j-v[i]]+v[i]);
    
    // print(dp.back().back());
    cout << dp.back();
}