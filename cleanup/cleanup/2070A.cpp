#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;

    // for (int i = 0; i <= 500; i++)
    //     if (i%3 == i%5)
    //         cout << i << ' ' << i%3 << '\n';
    // exit(0);


    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
ll slv(ll n){
    ll cnt = 0;
    for (int i = 0; i<=n; i++)
        if (i%3 == i%5)
            cnt++;
    return cnt;
}
void solve(){
    ll n; cin >> n;
    if (n < 15)
        kill(min(n+1, 3ll));
    
    ll ans = ((n/15)-1)*3;
    for (ll i = (n/15)*15; i <=n; i++){
        print(ans, i);
        if (i%15 < 3)
            ans++;
    }
    cout << ans+3;
}