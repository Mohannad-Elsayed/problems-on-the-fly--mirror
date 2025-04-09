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
bool issqrt(int n){
    int sq = sqrtl(n);
    return sq*sq == n;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;

    // int s = 0;
    // for (int i = 2; i < 1000000; i++){
    //     s += i;
    //     cout << s << ' ';
    //     if (issqrt(s)){
    //         print(s, i);
    //         exit(0);
    //     }
    // }
    // exit(0);


    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    ll n; cin >> n;
    if (issqrt((n * (n+1))/2))
        kill(-1);
    
}