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
        // print("test", tt);
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}
int solve(){
    ll k, l1, r1, l2, r2, p = 1, ans = 0; 
    cin >> k >> l1 >> r1 >> l2 >> r2;
    while(true){
        if (l1 * p > r2)
            break;
        ll l = l1, r = r1, m, fx = -1, lx = -1;
        while(l <= r){
            m = (l+r)/2;
            if (m * p >= l2)
                fx = m, r = m-1;
            else   
                l = m+1;
        }
        l = l1, r = r1;
        while(l <= r){
            m = (l+r)/2;
            if (m*p <= r2)
                lx = m, l = m+1;
            else    
                r = m-1;
        }
        p *= k;
        if (fx == -1)
            continue;
        // print(p, fx, lx);
        ans += lx - fx + 1;
    }
    cout << ans;
    //________________________
    return 0;
}