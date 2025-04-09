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
    int n; cin >> n;
    vector<int> v(n), u;
    for (auto &i : v)
        cin >> i;
    
    set<int> ste;
    for (int i = 0; i < n; i++){
        if (ste.count(v[i]))
            continue;
        u.push_back(v[i]);
        ste.insert(v[i]);
    }
    int remain = n - u.size();
    // print(remain, n, u.size());
    for (auto x : u)
        cout << x << ' ';
    for (int i = n, cnt = 0; cnt < remain ;i--)
        if (!ste.count(i))
            cout << i << ' ', cnt++;
    //________________________
    return 0;
}