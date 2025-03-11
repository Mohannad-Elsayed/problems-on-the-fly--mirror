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
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int cntb(int x, int b){
    int cycle = (1 << (b+1));
    int ans = (x/cycle) * (1 << b);
    int rem = x%cycle;
    ans += max(0, rem - (1<<b)+1);
    return ans;
}
void solve(){
    int l, r; cin >> l >> r;
    int mx = -1;
    for (int i = 0; i<20; i++)
        mx = max(mx, cntb(r, i) - cntb(l-1, i));
    cout << r-l+1-mx;
}
