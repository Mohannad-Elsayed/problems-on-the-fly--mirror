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
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
bool f1(ll n){
    n = (n * (n+1))/2;
    ll sq = sqrt(n);
    return sq*sq == n;
}
bool f2(ll n){
    n = (n * (n+1))/2;
    ll sq = sqrtl(n);
    return sq*sq == n;
}
void solve(){
    ll N = 5e5;
    for (ll i = 1; i <= N; i++){
        if (f1(i) != f2(i))
            print(f1(i), f2(i), i);
    }
}