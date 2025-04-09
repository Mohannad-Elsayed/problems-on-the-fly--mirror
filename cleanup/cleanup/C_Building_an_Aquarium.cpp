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
    ll n, x; 
    cin >> n >> x;

    ll arr[n];
    for (int i = 0; i<n; i++)
        cin >> arr[i];
    
    ll l = 0, r = 5e13, m, res;

    function<bool(ll)> can = [&](ll mid) -> bool {
        ll accu = 0;
        for (int i = 0; i<n; i++){
            if (arr[i] < mid){
                accu += mid - arr[i];
            }
        }
        return accu <= x;
    };


    while(l<=r){
        m = l + (r-l)/2;
        if (can(m)){
            l = m+1;
            res = m;
        } else r = m-1;
    }

    cout << res;
    //________________________
    return 0;
}