#define ONLINE_JUDGE
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

int answer(int n){
    int cnt = 0;
    for (auto x : {15, 6, 3, 1}){
        cnt += n/x;
        n %= x;
    }
    return cnt;
}
void solve(){
    int n, ans = 1e9;
    int T = 15;
    cin >> n;
    if (n < 10)
        kill(answer(n));
    
    if (n < 20)
        kill(min(answer(n), answer(n-10)+1));
    
    kill(min({answer(n), answer(n-10)+1, answer(n-20)+2}));
}