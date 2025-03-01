// #define ONLINE_JUDGE
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
#define each(x, v) for (auto &(x) : (v))
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<vector<int>> g(n);
    for (int i = 0; i+1 < n; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n);
    function<void(int)> dfs = [&](int u){
        if (vis[u])
            return;
        vis[u] = 1;
        each(v, g[u])
            dfs(v);
        cout << u+1 << ' ';
    };
    dfs(b);
    // cout << b;
}