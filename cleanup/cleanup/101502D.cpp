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
vector<vector<int>> reach {
    {}, // 0
    {2, 3, 4, 5}, // 1
    {1, 3, 4, 6}, // 2
    {1, 2, 5, 6}, // 3
    {1, 2, 5, 6}, // 4
    {1, 3, 4, 6}, // 5
    {2, 3, 4, 5}, // 6
};
int N = 2*10000;
vector<int> dp(N+1, -1);
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int top = 1;
    queue<pair<int, int>> q; // sum, top
    q.push({0, 1});
    for (int level = 0, sz = 1; q.size(); level++, sz = q.size()) {
        while(sz--) {
            auto [sum, top] = q.front();
            q.pop();
            if (dp[sum] != -1)
                continue;
            dp[sum] = level;
            each(ver, reach[top]) {
                if (sum + ver >= N)
                    continue;
                q.push({sum+ver, ver});
            }
        }
    }
    // for (int i = 0; i<101; i++) {
    //     cout << i << ' ' << dp[i] << '\n';
    // }
    // exit(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n; cin >> n;
    cout << dp[n];
}