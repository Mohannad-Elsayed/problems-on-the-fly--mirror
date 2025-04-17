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
    int n, m, u, v; cin >> n >> m;
    vector<vector<int>> g(n+1);
    set<pair<int, int>> ne, curr;
    vector<bool> vis(n+1);
    for (int i = 0; i<m; i++) {
        cin >> u >> v;
        curr.emplace(u, v);
        g[u].push_back(v);
    }
    function<void(int, int)> dfs = [&](int u, int par) {
        if (!curr.count(make_pair(par, u)))
            ne.emplace(par, u);
        vis[u] = 1;
        each(ver, g[u])
            if (!vis[ver])
                dfs(ver, par);
    };
    for (int i = 1; i<=n; i++) {
        vis = vector<bool>(n+1);
        dfs(i, i);
    }
    print(ne);
    cout << ne.size() << '\n';
    each(p, ne)
        cout << p.first << ' ' << p.second << '\n';
}