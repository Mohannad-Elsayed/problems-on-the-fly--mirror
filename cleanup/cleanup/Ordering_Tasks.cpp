#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
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
uniform_int_distribution<> uid(1, 1ll<<31);
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
    int n, m; cin >> n >> m;
    while(n) {
        vector<vector<int>> g(n+1);
        vector<int> ans, vis(n+1);
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            each(ver, g[u])
                if (!vis[ver])
                    dfs(ver);
            ans.push_back(u);
        };
        while(m--) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
        }
        print(g);
        for (int i = 1; i<=n; i++)
            if (!vis[i])
                dfs(i);
        reverse(all(ans));
        print(ans);
        each(i, ans)
            cout << i << " \n"[i == ans.back()];
        cin >> n >> m;
    }
}