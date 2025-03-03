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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto &vv : v)
        for (auto &e : vv)
            cin >> e;

    for (int i = 0; i < n; i++){
        for (int j = 0; j<m; j++){
            int nei = 4;
            if (!i || i == n-1)
                nei--;
            if (!j || j == m-1)
                nei--;
            if (v[i][j] > nei)
                return cout << "NO", 0;
            v[i][j] = nei;
        }
    }
    cout << "YES\n";
    for (auto &vv : v){
        for (auto &e : vv){
            cout << e << ' ';
        } if(&vv != &v[n-1])cout << '\n';}
    //________________________
    return 0;
}