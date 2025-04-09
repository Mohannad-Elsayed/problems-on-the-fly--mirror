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
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<31);
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
#define int ll
void solve() {
    int n; cin >> n;
    vector<int> od, ev, v;
    for (int i = 0; i<n; i++) {
        int t; cin >> t;
        if (t&1)
            od.push_back(t);
        else ev.push_back(t);
        v.push_back(t);
    }
    int ans = 0, mn = min(od.size(), ev.size());
    sort(rall(od));
    sort(rall(ev));
    ans = accumulate(od.begin(), od.begin()+mn, 0ll) + accumulate(ev.begin(), ev.begin()+mn, 0ll) - (max(od.size(), ev.size()) - mn);
    print(od, ev);
    // while(od.size() && ev.size()) {
    //     ans += od.back() + ev.back();
    //     od.pop_back(); ev.pop_back();
    // }
    cout << max({*max_element(all(v)), ans});
}