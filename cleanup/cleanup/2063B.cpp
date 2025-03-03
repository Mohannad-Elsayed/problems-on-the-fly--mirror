#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << x, 0;
#define killn(x) return cout << x << '\n', 0;

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
    ll n, l, r, m; 
    cin >> n >> l >> r;
    m = r-l+1;
    vector<ll> v(n);
    each(x, v)
        cin >> x;

    vector<ll> left, right;
    for (int i = 0; i<r; i++)
        left.emplace_back(v[i]);
    for (int i = l-1; i < n; i++)
        right.emplace_back(v[i]);
    
    sort(all(left));
    sort(all(right));

    ll mn1 = 0, mn2 = 0;
    for (int i = 0; i<m; i++)
        mn1+=left[i];
    for (int i = 0; i<m; i++)
        mn2+=right[i];

    cout << min(mn1, mn2);

    //________________________
    return 0;
}