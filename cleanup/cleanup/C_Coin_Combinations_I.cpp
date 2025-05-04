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
constexpr int mod = 1e9+7;
void add(int& a, const int b) {
    a += b;
    a %= mod;
}
int rec(int sum, vector<int>& coin, vector<int>& dp) {
    // bases
    if (sum < 1)
        return sum == 0;
    if (~dp[sum])
        return dp[sum];
    int& ret = dp[sum];
    ret = 0;
    each(c, coin)
        add(ret, rec(sum-c, coin, dp));
    return ret;
}
void solve() {
    int ans, n, k; cin >> n >> k;
    vector<int> coins(n), dp(k+1, -1);
    getv(coins);
    cout << rec(k, coins, dp);
}