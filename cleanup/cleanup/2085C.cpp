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
void stress() {
    ll mx = 0, my = 0;
    int N = 2000;
    for (ll x = 1; x < (int)N; x++) {
        for (ll y = x+1; y < (int)N; y++) {
            for (ll k = 0; k<(ll)N; k++) {
                if (((x + k) + (y + k)) == ((x + k) ^ (y + k))) {
                    chmax(mx, abs(x-k));
                    chmax(my, abs(y-k));
                }
            }
        }
    }
    print(mx, my);
    exit(0);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // stress();
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void solve() {
    ll x, y, k = 0, tx, ty; cin >> x >> y;
    tx = x, ty = y;
    // for (int i = 0; i<62; i++) {
    //     ll k = 1ll << i;
    //     if (((x + k) + (y + k)) == ((x + k) ^ (y + k))) {
    //         print((x + k) + (y + k));
    //         print((x + k) ^ (y + k));
    //         kill(k);
    //     }
    // }
    if (!(x & y))
        kill(0);
    
    for (int i = 0; i<60; i++) {
        if (((x >> i)&1) & ((y >> i)&1)) {
            ll val = 1ll << i;
            x += val;
            y += val;
            k += val;
            print(x, y, k, i);
        }
    }
    print(tx, ty, k);
    if ((k <= (ll)1e18) && ((tx + k) + (ty + k)) == ((tx + k) ^ (ty + k))) {
        // print((tx + k) + (ty + k));
        // print((tx + k) ^ (ty + k));
        kill(k);
    }
    cout << -1;
}

// 100100100100100100100
//  10010010010010010100
//                   100