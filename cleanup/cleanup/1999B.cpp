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
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int sim(int a, int b){
    return a > b ? 1 : a < b ? -1 : 0;
}
void solve() {
    int a, b, c, d; 
    cin >> a >> b >> c >> d;
    int ans = 0;
    if (sim(a, c) + sim(b, d) > 0)
        ans++;
    if (sim(a, d) + sim(b, c) > 0)
        ans++;
    if (sim(b, c) + sim(a, d) > 0)
        ans++;
    if (sim(b, d) + sim(a, c) > 0)
        ans++;
    cout << ans;
}