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
    pre();
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    // ll n = 6454263528;
    // cout << n - 999 - 9-99999;
    // exit(0);
    //________________________
    return 0;
}

int solve(){
    ll n; 
    cin >> n;
    ll tn = n;
    ll ans = INT_MAX;

    string nines[11] = {
        "9", 
        "99", 
        "999", 
        "9999", 
        "99999", 
        "999999", 
        "9999999", 
        "99999999", 
        "999999999", 
        "9999999999", 
        "99999999999", 
    };

    function<bool(ll)> have = [&](ll a) -> bool {
        return to_string(a).find('7') != string::npos;
    };

    each(i, nines){
        ll cnt = 0;
        n = tn;
        while(!have(n)){
            n += stoll(i);
            cnt++;
        }
        ans = min(ans, cnt);
    }

    // print(tn, ans);
    cout << ans;
    //________________________
    return 0;
}