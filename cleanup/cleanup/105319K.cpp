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
    // freopen("area.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    set<string> allf, wf, in_stage, to_be_put_in_stage;
    for (int i = 0; i<n; i++) {
        string s; cin >> s; 
        allf.insert(s);
    }
    for (int i = 0; i<m; i++) {
        string s; cin >> s; 
        in_stage.insert(s);
    }
    for (int i = 0; i<k; i++) {
        string s; cin >> s; 
        to_be_put_in_stage.insert(s);
    }

    int ans1 = 0;
    each(s, in_stage)
        ans1 += !to_be_put_in_stage.count(s);
    each(s, to_be_put_in_stage)
        ans1 += !in_stage.count(s);

    print(ans1, k+1, n-k+1, n, k);
    cout << min({ans1, k+1, n-k+1});
}