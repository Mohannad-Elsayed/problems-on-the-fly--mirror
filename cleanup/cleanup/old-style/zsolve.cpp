#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()

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
    #define printarr(...)
    #pragma GCC optimize("O3,unroll-loops,Ofast")
    // #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.in", "rt", stdin);
        // freopen("out.out", "wt", stdout); freopen("out.out", "wt", stderr); 
        
    #endif
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
    ll n, sumodd{}, sumeven{}; cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    sort(arr, arr+n);
    for (int i = 0; i<n; i++){
        if (i < n/2)
            sumodd += arr[i];
        else   
            sumeven += arr[i];
    }
    print(sumodd, sumeven);
    cout << sumodd * sumodd + sumeven * sumeven;
    //________________________
    return 0;
}