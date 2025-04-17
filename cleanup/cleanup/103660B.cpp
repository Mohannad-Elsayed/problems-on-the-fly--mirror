// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
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
int rnglr(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
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
    int n, k, x, y, mx = -1;
    cin >> n >> k >> x >> y;
    while(n--) {
        int t; cin >> t;
        chmax(mx, t);
    }
    int l = 1, r = k, mid, res1 = 1e16, res2 = 1e16, val;
    while (l <= r) {
        mid = l+r >> 1;
        val = mid * x;
        if (val >= mx) {
            res1 = mid;
            r = mid-1;
        } else l = mid+1;
    }
    l = k+1, r = 1e15;
    while (l <= r) {
        mid = l+r >> 1;
        val = k * x + (mid - k) * y;
        if (val >= mx) {
            res2 = mid;
            r = mid-1;
        } else l = mid+1;
    }
    cout << min(res1, res2);
}