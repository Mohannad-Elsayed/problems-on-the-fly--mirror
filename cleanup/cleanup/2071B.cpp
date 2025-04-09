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
bool issqrt(ll n){
    ll sq = sqrtl(n);
    return sq*sq == n;
}
void solve(){
    ll n; cin >> n;
    if (issqrt(n*(n+1)/2))
        kill(-1);
    vector<int> v(n);
    iota(all(v), 1);
    while(true){
        random_shuffle(all(v));
        ll s = 0, b = 1;
        for (int i = 0; i<n; i++){
            s += v[i];
            if (issqrt(s)){
                b = 0;
                break;
            }
        }
        if (b){//
            each(i, v)
                cout << i << ' ';
            return;
        }
    }
}