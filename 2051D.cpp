#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
        print("\n\n");
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}
int solve(){
    ll n, x, y, sum;
    cin >> n >> x >> y;
    vector<ll> v(n), sorted;
    each(i, v)
        cin >> i;
    
    sorted = v;
    sort(all(sorted));
    sort(all(v));
    sum = accumulate(all(sorted), 0ll);
    print(sum);
    // print(v);
    print(sorted);
    ll cnt = 0;
    for (int i = 0; i<n; i++){
        ll currsum = sum - v[i];
        print(currsum);
        ll l = i+1, r = n-1, m, ind_x = i, ind_y = n;

        // largest number when removed still larger than x
        while(l<=r){
            m = (l+r)/2;
            ll currsum_ = currsum - v[m];
            if (currsum_ >= x){
                ind_x = m;
                l = m+1;
            } else r = m-1;
        }

        // smallest number when removed still smaller than y
        l = i+1, r = n-1;
        while(l<=r){
            m = (l+r)/2;
            ll currsum_ = currsum - v[m];
            if (currsum_ <= y){
                ind_y = m;
                r = m-1;
            } else l = m+1;
        }
        print(ind_x, ind_y);
        print(v[ind_x], v[ind_y]);
        
        if (ind_x >= ind_y)
            cnt += ind_x - ind_y+1;
    } 
    cout << cnt;
    //________________________
    return 0;
}