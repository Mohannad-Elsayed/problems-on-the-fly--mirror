#define ONLINE_JUDGE
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
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int stress(int &n, vector<int> &v) {
    set<int> ste;
    for (int i = 0; i<n; i++) {
        int curr = 0;
        for (int j = i; j<n; j++) {
            curr |= v[j];
            ste.insert(curr);
        }
    }
    print(ste);
    print(ste.size());
    return ste.size();
}
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    getv(v);
    int ans = accumulate(all(v), 0, [&](int a, int b) {
        return a|b;
    });
    print(ans);
    ll pop = __builtin_popcount(ans);
    set<int> ste(all(v));
    cout << min(ll(1ll * ste.size() * (ste.size() + 1) / 2), 
        (pop*(pop+1))/2);
    print(__builtin_popcount(ans));
    bitset<32> b(ans);
    print(b);
    // stress(n, v);
}