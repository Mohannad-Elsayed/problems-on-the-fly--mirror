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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> vp(n);
    each(p, vp)
        cin >> p.first >> p.second;
    // sort(all(vp));
    // sort(all(vp), [&](pair<int, int> a, pair<int, int> b) {
    //     if (a.second == b.second) 
    //         return a.first > b.first;
    //     return a.second < b.second;
    // });
    sort(all(vp), [&](pair<int, int> a, pair<int, int> b) {
        return a.first-a.second > b.first-b.second;
    });
    print(vp);
    auto ch = [&](int m) -> bool {
        each(p, vp) {
            // print(m, p);
            if (m < p.first) {
                return false;
            }
            m -= p.second;
        }
        // print(m);
        return m >= 0;
    };
    // ch(6);
    int l = 1, r = 1e18, mid, res = -1;
    while(l <= r) {
        mid = l + (r-l)/2;
        // print(mid, ch(mid));
        if (ch(mid)) {
            res = mid;
            r = mid-1;
        } else l = mid+1;
    }
    cout << res;
}