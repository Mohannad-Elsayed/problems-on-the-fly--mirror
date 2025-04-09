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
    int n; cin >> n;vector<int>v(n);getv(v);sort(all(v));
    int o, e;
    o = e = 0;
    each(i, v) {
        if (i == -1)
            continue;
        i&1 ? o++ : e++;
    }

    if(o%2 == 0 && e%2 == 0)
        kill("YES");

    for (int i = 0; i+1<n; i++) {
        if (v[i] + 1 == v[i+1])
            v[i] = v[i+1] = -1, o--, e--;
        if(o%2 == 0 && e%2 == 0)
            kill("YES");
    }
    kill(o%2 == 0 && e%2 == 0 ? "YES" : "NO");
}