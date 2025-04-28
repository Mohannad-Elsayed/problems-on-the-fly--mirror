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
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void solve() {
    int n, m, k; 
    cin >> n >> m >> k;
    vector<pair<int, int>> vp;
    for (int i = 1; i * i <= k; i++)
        if (k % i == 0)
            vp.emplace_back(i, k/i);
    print(vp);
    vector<vector<int>> grid(n+1, vector<int>(m+1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j <= m; j++) {
            grid[i][j] = grid[i][j] + grid[i-1][j] + grid[i][j-1] -
                          grid[i-1][j-1];
        }
    }
    auto printg = [&]() {
        // each(vv, grid) {
        //     each(i, vv) 
        //         cout << i << ' ';
        //     cout << '\n';
        // }
    };
    // printg();
    int ans = LLONG_MIN, curr;
    for (auto [a, b] : vp) {
        for (int i = 1; i+a-1 <= n; i++) {
            for (int j = 1; j+b-1 <= m; j++) {
                curr = grid[i+a-1][j+b-1] -
                    grid[i-1][j+b-1] - 
                    grid[i+a-1][j-1] + 
                    grid[i-1][j-1];
                chmax(ans, curr);
                print(ans, i, i+a-1, j, j+b-1);
            }
        }
        for (int i = 1; i+b-1 <= n; i++) {
            for (int j = 1; j+a-1 <= m; j++) {
                curr = grid[i+b-1][j+a-1] -
                    grid[i-1][j+a-1] - 
                    grid[i+b-1][j-1] + 
                    grid[i-1][j-1];
                chmax(ans, curr);
                print(ans, i, i+b-1, j, j+a-1);
            }
        }
    }
    print(ans);
    if (ans != LLONG_MIN) 
        kill(ans);
    cout << "No such rectangle.";
}