#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << (x), 0;
#define killn(x) return cout << (x) << '\n', 0;

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
// #define ONLINE_JUDGE
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
    // cin >> tt;
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
    ll n, q, t; 
    cin >> n >> q;
    
    ll arr[n+1]{};
    // 0  2 5 - - 
    for (int i = 1; i<=n; i++){

        cin >> arr[i];

    }
    sort(arr, arr+n);

    for (int i = 1; i<=n; i++)
        arr[i] += arr[i-1];

    // printarr(arr, n+1);
    while(q--){
        cin >> t;
        int l = 0, r = n, m, res;
        while(l<=r){
            m = (l+r)/2;
            if (arr[m] <= t){
                res = m;
                l = m+1;
            } else r = m-1;
        }
    
        cout << res << '\n';
    }
    //________________________
    return 0;
}