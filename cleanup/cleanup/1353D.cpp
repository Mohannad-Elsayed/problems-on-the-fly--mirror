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
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
vector<pair<int, int>> vp;
void rec(int l, int r) {
    // base
    if (l > r)
        return;
    // recurse
    vp.emplace_back(l, r);
    int mid = (r-l)/2;
    rec(l, l+mid-1);
    rec(l+mid+1, r);
}
void solve() {
    vp.resize(0);
    int n; cin >>n;
    vector<int> ans(n);
    rec(0, n-1);
    sort(all(vp), [&](pair<int, int> a, pair<int, int> b) {
        if (a.second - a.first == b.second - b.first) {
            return a.first < b.first;
        }
        return a.second - a.first > b.second - b.first;
    });
    print(vp);
    for (int i = 1; i <= n; i++){
        auto [f, s] = vp[i-1];
        ans[f + (s-f)/2] = i;
    }
    print(ans);
    each(i, ans)
        cout << i << ' ';
}