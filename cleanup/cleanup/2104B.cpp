#define ONLINE_JUDGE
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
    int n, mx = -1; cin >> n;
    vector<int> v(n), suf(n), mxv(n);
    getv(v);
    suf.back() = v.back();
    for(int i = 0; i<n; i++) {
        chmax(mx, v[i]);
        mxv[i] = mx;
    }
    mx = *max_element(all(v));
    for (int i = n-2; ~i; i--) 
        suf[i] += suf[i+1] + v[i];
    reverse(all(suf));
    reverse(all(mxv));
    print(suf);
    print(mxv);
    cout << max(mx, suf.front()) << ' ';
    for (int i = 1; i<n; i++) {
        cout << max(suf[i], suf[i-1]+mxv[i]) << ' ';
    }
}