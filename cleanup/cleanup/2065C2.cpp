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
    int n, m; cin >> n >> m;
    vector<ll> v(n), q(m);
    each(i, v)
        cin >> i;
    each(i, q)
        cin >> i;
    sort(all(q));
    // v.insert(v.begin(), INT_MIN);
    // v.insert(v.end(), INT_MAX);
    // print(v);
    // print(q);

    ll mn = v[0];
    each(i, q)
        mn = min(mn, i-v[0]);
    v[0] = mn;
    mn = v.back();
    each(i, q)
        mn = max(mn, i-v.back());
    v.back() = mn;

    for (int i = 1; i+1<n; i++){
        int l = 0, r = m-1, m, res = -1;
        while(l<=r){
            m = (l+r)/2;
            if (q[m] - v[i] >= v[i-1]){
                res = m;
                r = m-1;
            } else l = m+1;
        }
        if (~res && v[i] > q[res] - v[i])
            v[i] = q[res] - v[i];
        print(i, res);
        print(v);
    }
    kill(is_sorted(all(v))  ? "YES" : "NO");
    //________________________
    return 0;
}