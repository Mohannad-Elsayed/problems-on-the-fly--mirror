// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
    #define print(...) ((void)0)
    #define printarr(...) ((void)0)
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
template<class T> T rnglr(T l, T r) {return uniform_int_distribution<T>(l, r)(rng);}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("area.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n; cin >> n; 
    vector<int> h(n), vl(n), vr(n);
    getv(h);
    for (int i = 0; i<n; i++)
        cin >> vl[i] >> vr[i];
    for (int i = 1; i<n; i++) 
        chmax(vl[i], vl[i-1]);
    for (int i = n-2; ~i; i--)
        chmin(vr[i], vr[i+1]);
    for (int i = n-2; ~i; i--)
        if (vl[i] > vr[i])
            kill(-1);
    print(vl);
    print(vr);
}