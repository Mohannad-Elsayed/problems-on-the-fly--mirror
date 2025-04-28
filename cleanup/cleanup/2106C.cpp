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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    getv(a);
    getv(b);
    set<int> xes;
    for (int i = 0; i<n; i++) {
        if (b[i] != -1) {
            xes.insert(a[i] + b[i]);
        }
    }
    // print(xes);
    if (xes.size() > 1) 
        kill(0);
    if (xes.size() == 1) {
        int x = *xes.begin();
        for (int i = 0; i<n; i++) {
            // a[i] + b[i] == x
            // b[i] <= k;
            int bi = x - a[i];
            if (bi > -1 && bi <= k)
                continue;
            kill(0);
        }
        kill(1);
    }
    int mn = *min_element(all(a)), mx = *max_element(all(a));
    kill(max(0ll, k+mn-mx+1));
}