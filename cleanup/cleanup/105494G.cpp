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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void solve() {
    int n, k, currk = 0, lstk, lstidx; 
    cin >> k >> n;
    vector<pair<int, int>> vp(n); // need, prize
    vector<int> ans;
    each(i, vp)
        cin >> i.second >> i.first;
    sort(all(vp), [&](pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first)
            return a.first < b.first;
        return b.second > a.second;
    });
    print(vp);
    for (int i = 0; i < n;) {
        lstidx = -1;
        while(vp[i].first <= currk) {
            lstk = vp[i].second;
            lstidx = i+1;
            i++;
        }
        if (lstidx == -1)
            kill(-1);
        ans.push_back(lstidx);
        currk += lstk;
        i = lstidx;
        print(i);
    }
    print(ans);
}