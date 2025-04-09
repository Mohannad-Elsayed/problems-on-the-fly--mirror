#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << x, 0;
#define killn(x) return cout << x << '\n', 0;

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #pragma GCC optimize("O3,unroll-loops,Ofast")
    // #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    pre(); 
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}
vector<vector<int>> tree;
int solve(){
    int n; cin >> n;
    tree = vector<vector<int>>(n);

    for (int i = 1; i<n; i++){
        int u, v; 
        cin >> u >> v; 
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int max_edges = 0, mxindex = -1;
    for (int i = 0; i<tree.size(); i++){
        if (tree[i].size() > max_edges){
            max_edges = tree[i].size();
            mxindex = i;
        }
    }
    pair<int, int> vert;
    vert.first = mxindex;
    for (int i = 0; i<tree.size(); i++){
        if (find(all(tree[i]), mxindex) != tree[i].end()){
            tree[i].erase(find(all(tree[i]), mxindex));
        }
    }
    tree[mxindex].clear();
    print(max_edges, mxindex);
    print(tree);

    max_edges = 0, mxindex = -1;
    for (int i = 0; i<tree.size(); i++){
        if (i == vert.first)
            continue;
        if (tree[i].size() > max_edges){
            max_edges = tree[i].size();
            mxindex = i;
        }
    }
    if (mxindex == -1)
        return cout << n-2, 0;
    print(max_edges, mxindex);
    vert.second = mxindex;
    for (int i = 0; i<tree.size(); i++){
        if (find(all(tree[i]), mxindex) != tree[i].end()){
            tree[i].erase(find(all(tree[i]), mxindex));
        }
    }
    tree[mxindex].clear();
    print(tree);
    vector<int> vis(n);
    int cnt = 0;
    function<void(int)> dfs = [&](int vertex){
        if (vis[vertex])
            return;
        vis[vertex] = 1;
        each(x, tree[vertex])
            dfs(x);
    };
    for (int i = 0; i<n; i++){
        if (i == vert.first || i == vert.second)
            continue;
        if (!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;

    //________________________
    return 0;
}