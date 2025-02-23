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
    
    //________________________
    return 0;
}
bool have(ll n){
    ll cnt = 0, tn = n;
    while(tn){
        if (tn % 10 && n % (tn % 10))
            return true;
        tn /= 10;
    }
    return false;
}
int solve(){
    ll n;
    cin >> n;
    while(have(n)){
        ll tn = n, d;
        while(tn){
            d = tn % 10;
            if (d && n % d){
                n += d - n%d;
                break;
            }
            tn /= 10;
        }
    }
    cout << n;
    //________________________
    return 0;
}