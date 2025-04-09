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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void solve() {
    int n, allsum, m; cin >> n >> m;
    vector<int> v(n), pre(n), suf(n);
    getv(v);
    allsum = accumulate(all(v), 0ll);
    pre[0] = v[0];
    for (int i = 1; i<n; i++)
        pre[i] += v[i] + pre[i-1];
    print(pre);
    suf[n-1] = v[n-1];
    for (int i = n-2; ~i; i--)
        suf[i] += suf[i+1] + v[i];
    print(suf);

    for (int i = 0; i<n; i++) {
        int v1 = allsum - v[i] + m;
        int v2 = LLONG_MIN, v3 = LLONG_MIN;
        if (i-1 > -1) {
            v2 = pre[i-1];
        }
        if (i+1 < n) {
            v3 = suf[i+1];
        }
        cout << max({v1, v2, v3}) << ' ';
    }
}