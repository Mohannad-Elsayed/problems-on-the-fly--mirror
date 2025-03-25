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
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
void stress() {
    int n; cin >> n;
    vector<int> v(n);
    getv(v);
    auto isvalid = [&]() -> bool {
        for (int i = 0; i+1<n; i++) {
            int a1 = v[0], a2 = v.back();
            for (int j = 0; j<=i; j++)
                a1 &= v[j];
            for (int j = i+1; j<n; j++)
                a2 &= v[j];
            if (a1 != a2)
                return false;
        }
        return true;
    };
    auto printb = [&](int a) {
        do {
            cout << (a&1);
            a /= 2;
        } while(a);
        cout << ' ';
    };
    sort(all(v));
    do {
        if (isvalid()) {
            each(i, v) 
                printb(i);
            cout << "\n\n";
        }
    } while(next_permutation(all(v)));
}
void solve() {
    stress();
}