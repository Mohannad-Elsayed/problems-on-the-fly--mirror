#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
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
int solve(){
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> longestsofar(n+1), vis(n+1);

    function<int(int)> dfs = [&](int u) -> int {
        if (vis[u]) return longestsofar[u];
        vis[u] = 1;
        each(v, g[u]) 
            longestsofar[u] = max(longestsofar[u], 1 + dfs(v));
        return longestsofar[u];
    };

    for (int i = 1; i<=n; i++) {
        int tmp; cin >> tmp;
        g[i].push_back(tmp);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) 
        ans = max(ans, dfs(i));
    // print(longestsofar);
    cout << ans;
    //________________________
    return 0;
}


