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
uniform_int_distribution<> uid(1, 1ll<<30);
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
    int n, k, ans = 0; cin >> n >> k;

    string s;
    vector<int> scores(n), mnpal(n);
    vector<string> vs(n);

    getv(vs);
    // print(vs);
    for (int i = 0; i<n; i++) {
        int sz = vs[i].size();
        for (int pal = 0; pal < sz/2; pal++) {
            mnpal[i] += vs[i][pal] != vs[i][sz-pal-1];
        }
    }
    getv(scores);

    print(mnpal);
    print(scores);
    int currsumk = 0, currsumsc = 0;
    for (int l = 0, r = 0; l < n && r < n; l++) {
        while(r < n && currsumk + mnpal[r] <= k) {
            if(currsumsc > ans) ans = currsumsc;
            currsumsc += scores[r];
            currsumk += mnpal[r];
            if(currsumsc > ans) ans = currsumsc;
            r++;
        }
        if(l < r) {
            currsumk -= mnpal[l];
            currsumsc -= scores[l];
        } else {
            r = l + 1;
        }
        // if(currsumsc > ans) ans = currsumsc;
    }
    cout << ans;
}