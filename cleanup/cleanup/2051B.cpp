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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll l = 0, r = 1e9, m, res;
    while(l <= r){
        m = (l+r)/2;
        ll curres = m/3 * a + m/3 * b + m/3 * c;
        curres += (m%3 >= 1) * a + (m%3 >= 2) * b;
        if (curres >= n){
            res = m;
            r = m-1;
        } else l = m+1;
    }
    cout << res;
    //________________________
    return 0;
}



