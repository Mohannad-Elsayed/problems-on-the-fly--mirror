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
    #define printarr(...)
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}
// abbadccd
int solve(){
    int n, q, x; 
    cin >> n >> q;
    string s; cin >> s;
    while(q--){
        cin >> x;
        int st = x, en = n-x+1;
        if (st > en)
            swap(st, en);
        
        st--, en--;
        // print(st, en);
        for (int i = st; i<=en/2; i++)
            swap(s[i], s[n-i-1]);
    }
    cout << s;
    //________________________
    return 0;
}