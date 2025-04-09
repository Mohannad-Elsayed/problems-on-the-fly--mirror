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
    int n, m; 
    cin >> n >> m;
    vector<int> v(n), perm(n), sorted(n);
    getv(v);
    getv(perm);
    for (int i = 0; i<n; i++) {
        sorted[i] = v[perm[i]-1];
    }
    print(sorted);
    auto valid = [&](int _mid) { // if we take from mid to end, all pairs differences should be divisible by m
        // vector<int> ne;
        // for (int i = _mid; i<n; i++) 
        //     ne.emplace_back(sorted[i]); 
        // sort(all(ne));
        // print(ne);
        for (int i = _mid; i < n; i++) {
            if (abs(sorted[i]-sorted[i-1])%m)
                return false;
        }
        return true;
    };

    int l = 0, r = n-1, mid, ans = 0;
    while(l <= r) {
        mid = (l+r)/2;
        if (valid(mid)) {
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }

    print(ans);
    cout << ans;
}