// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
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
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    ll n, ans = LLONG_MAX; cin >> n;
    // map<int, int> mp {{6, 15}, {8, 20}, {10, 25}};
    // for(ll x : {6, 8, 10}){
    //     ll curr = (n/x) * mp[x];
    //     ll md = n%x;
    //     curr += bool(md) * (md < 7 ? mp[6] : (md < 9 ? mp[8] : mp[10]));
    //     ans = min(ans, curr);
    // }
    // cout << ans;
    cout << (n/6 + bool(n%6)) * 15;
}