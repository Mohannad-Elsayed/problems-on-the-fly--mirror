#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
int solve(){
    ll n, d; cin >> n >> d;
    vector<int> res(1, 1);
    if (n > 2 || d%3 == 0){
        res.push_back(3);
    }
    if (d == 9 || (n >= 3 && d % 3 == 0) || n >= 6)
        res.push_back(9);
    if (d%5 == 0)
        res.push_back(5);
    
    if (d == 7 || n > 2)
        res.push_back(7);
    
    sort(all(res));
    print(res);
    each(x, res)
        cout << x << ' ';
    //________________________
    return 0;
}