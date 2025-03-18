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
template<class T> void getv(T& v) {each(i, v)cin>>i;}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    getv(v);
    sort(all(v));
    int sum = accumulate(all(v), 0ll);
    int m; cin >> m;
    while(m--) {
        int x, y, a, b, pa = -1, bpa, ans = 2e18;
        cin >> x >> y;
        auto ait = lower_bound(all(v), x);
        if (ait != v.end()) 
            chmin(ans, max(0ll, x-*ait) + max(0ll, y - sum + *ait));
        if (ait != v.begin())
            chmin(ans, max(0ll, x-*prev(ait)) + max(0ll, y - sum + *prev(ait)));
        cout << ans << '\n';
    }
    
}