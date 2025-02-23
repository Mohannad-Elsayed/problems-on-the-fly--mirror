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
    int n, m, k; cin >> n >> m >> k;
    vector<int> ms(m), qs(k);
    each(x, ms) cin >> x;
    each(x, qs) cin >> x;

    if (k < n-1)
        while(m--)
            cout << '0';
    else if (k == n)
        while(m--)
            cout << '1';
    else {
        string s;
        for (int i = 0; i<m; i++)
            s += '1';
        each(x, qs)
            s[x-1] = '0';
        cout << s;
    }

    //________________________
    return 0;
}