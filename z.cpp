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
#define int ll
int stress(int &n, vector<int> &v) {
    set<int> ste;
    for (int i = 0; i<n; i++) {
        int curr = 0;
        for (int j = i; j<n; j++) {
            curr |= v[j];
            ste.insert(curr);
        }
    }
    return ste.size();
}
int solve(int &n, vector<int> &v) {
    int ans = accumulate(all(v), 0, [&](int a, int b) {
        return a|b;
    });
    ll pop = __builtin_popcount(ans);
    if (n == 1)
        return 1;
    set<int> ste(all(v));
    return min(ll(ste.size() * (ste.size() + 1) / 2), 
        (pop*(pop+1))/2);
    bitset<32> b(ans);

}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> v(n);
        getv(v);
        if (solve(n, v) != stress(n, v)) {
            print(n);
            print(v);
            print(solve(n, v));
            print(stress(n, v));
            return 0;
        }
    }return 0;
}