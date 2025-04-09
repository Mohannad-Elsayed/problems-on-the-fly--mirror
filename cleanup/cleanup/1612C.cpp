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
ll get_first_k_rev(ll k, ll n) {
    // 1 2 3 4 5 6 {7 8 9} // ?k = 3 
    // [1 2 3 4 5 6] {7 8 9} // ?k = 3 
    // same as sum_1_n - sum_1_n-k
    ll v = n-k;
    return n*(n+1)/2 -  v*(v+1)/2;
}
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
    ll k, x; cin >> k >> x;
    if (x > (k*(k-1)/2)) {
        x -= (k*(k-1)/2);
        ll l = 1, r = k, m, res;
        res = r;
        while(l<=r){
            m = (l+r)/2;
            if (get_first_k_rev(m, k) >= x) {
                res = m;
                r = m-1;
            } else l = m+1;
        }
        kill(k+res-1);
    } else {
        ll l = 1, r = k-1, m, res = k-1;
        while(l<=r) {
            m = (l+r)>>1;
            if (m*(m+1)/2 >= x) {
                res = m;
                r = m-1;
            } else l = m+1;
        }
        kill(res);
    }
}