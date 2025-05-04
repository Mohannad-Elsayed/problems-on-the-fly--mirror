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
#define int ll
void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    getv(v);
    vector<vector<int>> segs(1), fk, lk;
    each(i, v) {
        if (segs.back().empty() || !((segs.back().back() ^ i) & 1))
            segs.back().push_back(i);
        else
            segs.push_back(vector<int>(1, i));
    }
    print(segs);
    fk = segs;
    lk = segs;
    each(vv, fk) {
        for (int i = 1; i <  vv.size(); i++)
            vv[i] += vv[i-1];
    }
    each(vv, lk) {
        reverse(all(vv));
        for (int i = 1; i <  vv.size(); i++)
            vv[i] += vv[i-1];
    }
    print(fk);
    print(lk);
    ll sum = 0, mx = *max_element(all(v));
    for (int currseg = 0; currseg < fk.size(); currseg++) {
        if (fk[currseg].size() <= k) {
            sum += fk[currseg].back();
            chmax(mx, sum);
        }
        else {
            sum += fk[currseg][k-1];
            chmax(mx, sum);
            sum = fk[currseg][k-1];
            for (int i = k; i < fk[currseg].size() ; i++) {
                sum += segs[currseg][i];
                sum -= segs[currseg][i-k];
                chmax(mx, sum);
            }
            sum = lk[currseg][k-1];
            chmax(mx, sum);
        }
    }
    cout << mx;
}