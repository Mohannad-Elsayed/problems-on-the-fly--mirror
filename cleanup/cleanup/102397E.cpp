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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    getv(v);
    int l = 1, r = n, m, res = -1;
    auto check = [&](int mid) -> bool {
        int curr = accumulate(v.begin(), v.begin()+mid, 0ll);
        if (curr >= k)
            return true;
        for (int i = mid; i < n; i++) {
            curr -= v[i-mid];
            curr += v[i];
            if (curr >= k)
                return true;
        }
        return false;
    };
    while(l<=r) {
        m = (l+r)/2;
        if (check(m)) {
            res = m;
            r = m-1;
        } else l = m+1;
    }
    cout << res;
}