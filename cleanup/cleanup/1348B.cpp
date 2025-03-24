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

void solve() {
    int n, k, mx = 0; cin >> n >> k;
    map<int, int> mp;
    vector<int> v(n), u;
    getv(v);
    each(i, v) {
        if (u.empty() || i != u.back())
            u.push_back(i);
        mp[i]++;
        chmax(mx, mp[i]);
    }
    if ((int) mp.size() > k)
        kill(-1);
    assert(mx * (int) u.size() < (int) 1e4);
    cout << (mx+3)*u.size() << '\n';
    for (int i = 0; i<mx+3; i++) 
        each(i, mp)
            cout << i.first << ' ';
}