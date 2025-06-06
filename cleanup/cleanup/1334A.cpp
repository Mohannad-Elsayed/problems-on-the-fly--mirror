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
    // finishes is always less than plays, plays and finishes doesn't go down
    int n; 
    cin >> n;
    vector<pair<int, int>> v(n);
    cin >> v[0].first >> v[0].second;
    for (int i = 1; i<n; i++)
        cin >> v[i].first >> v[i].second;
    
    // if (v[0].second > v[0].first)
    //         return cout << "NO", 0;
    for (int i = 1; i<n; i++){
        if ((v[i].second > v[i].first || v[i] < v[i-1]) ||
           (v[i].first - v[i-1].first < v[i].second - v[i-1].second))
            return cout << "NO", 0;
    }
    cout << "YES";
    //________________________
    return 0;
}