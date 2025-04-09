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
    ll n, k; cin >> n >> k;

    vector<pair<ll, ll>> v(n);
    each(i, v)
        cin >> i.first >> i.second;
    
    sort(all(v), [&](pair<ll, ll> a, pair<ll, ll> b) {
        return (a.second - a.first) < (b.second - b.first);
    });

    // print(v);

    ll sum = 0, ans = n;
    each(i, v)
        sum += i.second;
    if (sum > k)
        kill(-1);
    if (sum <= k)
        kill(n);
    
    for (int i = n-1; i > -1; i--){
        sum -= v[i].second;
        sum += v[i].first;
        ans--;
        if (sum > k)
            break;
    }
    kill(ans+1);
    //________________________
    return 0;
}