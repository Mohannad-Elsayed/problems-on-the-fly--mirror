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

/*
 * __builtin_clz(x): the number of zeros at the beginning of the number
 * __builtin_ctz(x): the number of zeros at the end of the number
 * __builtin_parity(x): the parity (even or odd) of the number of ones
 */
void stress(ll a, ll b, ll n) {
    ll f[n+1]{};
    f[0] = a;
    f[1] = b;
    for (int i = 2; i <= n; i++) {
        f[i] = (n | f[i-1] | f[i-2]);
    }
    kill(f[n]);
    // exit(0);
}
void solve() {
    ll a, b, n; 
    cin >> a >> b >> n;
    // stress(a, b, n);
    // return;
    if (n == 0)
        kill(a);
    if (n == 1)
        kill(b);
    int heighest = 31 - __builtin_clz(n);
    // print(heighest);
    ll res = a|b;
    if (n == 2)
        kill(2 | res);
    for (; ~heighest; heighest--) {
        res |= (1ll << heighest);
    }
    cout << res;

}

// 1011111111101111
// 1011111111111111
//             1001