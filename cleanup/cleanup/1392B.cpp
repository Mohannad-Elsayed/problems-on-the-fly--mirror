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
    ll n, k; cin >> n >> k;
    vector<ll> v(n), f, s;
    for (auto &i : v)
        cin >> i;

    ll d = *max_element(all(v));
    for (auto &e : v)
        e = d-e;
    f = v;
    d = *max_element(all(v));
    for (auto &e : v)
        e = d-e;
    s = v;

    function<void(vector<ll>&)> printv = [&](vector<ll> &vv){
        for (auto e : vv)
            cout << e << ' ';
    };
    if (k&1)
        printv(f);
    else 
        printv(s);

    //________________________
    return 0;
}