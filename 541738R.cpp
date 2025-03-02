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
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int N = 10000000;
ll isprfct(ll n){
    ll sq = sqrtl(n);
    while(sq*sq > n) sq--;
    while(sq*sq < n) sq++;
    return sq*sq == n;
}
void stress(){
    int k = 40;
    for (int i = 0; i<N; i++){
        int ps = i*i;
        if (isprfct(ps+k))
            print(i, ps, ps+k), exit(0);
    }
    exit(0);
}
void solve(){
    stress();
}