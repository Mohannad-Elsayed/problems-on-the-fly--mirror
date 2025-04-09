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
    ll n, mx = 0, mn, ans = 0; cin >> n;
    vector<ll> v(n);
    each(i, v)
        cin >> i, ans = max(ans, i);

    vector<int> stk, l(n), r(n);

    // from right to left, min to max?
    for (int i = 0; i<n; i++){
        while(stk.size() && v[stk.back()] >= v[i])
            stk.pop_back();
        
        l[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
        // print(stk);
    }
    print(l);
    stk.clear();
    for (int i = n-1; i>-1; i--){
        while(stk.size() && v[stk.back()] >= v[i])
            stk.pop_back();

        r[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
        // print(stk);

    }
    print(r);

    for (int i = 0; i<n; i++)
        ans = max(ans, (r[i]-l[i]-1) * v[i]);
    kill(ans);
    //________________________
    return 0;
}