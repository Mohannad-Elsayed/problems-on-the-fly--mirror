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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, m, q, t, a, b, x, y, mn, mn1, mn2, e1, e2, tmpt; cin >> n >> m >> q;
    vector<vector<array<int, 2>>> v(m+1, vector<array<int, 2>>(7*n+10, {4, 4}));
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> x;
            if (x%7 == 0 || x%7 == 6)
                continue;
            v[a][x][0] = 0;
            v[a][x][1] = 0;
        } else if (t == 2) {
            cin >> a >> x >> y;
            if (x%7 == 0 || x%7 == 6)
                continue;
            v[a][x][y-1] = 0;
        } else if (t == 3) {
            cin >> a >> b >> x >> t;
            e1 = 0;
            for (int i = x; i <= 7*n; i++) {
                if (i%7 == 0 || i%7 == 6)
                    continue;

                if (v[a][i][0] && v[b][i][0]) {
                    mn = min({t, v[a][i][0], v[b][i][0]});
                    t -= mn;
                    // v[a][i][0] -= mn;
                    // v[b][i][0] -= mn;
                    if (!t) {
                        e1 = i;
                        break;
                    }
                }

                if (v[a][i][1] && v[b][i][1]) {
                    mn = min({t, v[a][i][1], v[b][i][1]});
                    t -= mn;
                    // v[a][i][1] -= mn;
                    // v[b][i][1] -= mn;
                    if (!t) {
                        e1 = i;
                        break;
                    }
                }
            }
            cout << (e1 ? e1 : -1) << '\n';
        }
    }
}