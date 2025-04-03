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

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n+1);
    map<int, int> frq;
    for (int i = 1; i<=n; i++) {
        cin >> v[i];
        if (v[i])
            frq[v[i]]++;
    }
    while(q--) {
        int t, p, val; cin >> t;
        if (t == 1) {
            cin >> p >> val;
            if (v[p] && frq.count(v[p]))
                frq[v[p]]--;
            if (frq.count(v[p]) && frq[v[p]] == 0) {
                frq.erase(v[p]);
            } 
            v[p] = val;
            if (val)
                frq[val]++;
            print(frq);
            print(v);
        } else cout << frq.size() << '\n';
    }
}