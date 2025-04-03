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
uniform_int_distribution<> uid(1, 1ll<<30);
void solve();
int main() {
    // cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
const int OO = 1e9;
void solve() {
    int n, m, s, d, t; cin >> n >> m;
    int c = 1;
    while(n) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = 0; i<n; i++)
            g[i][i] = 0;
        for (int i = 0; i<m; i++) {
            int c1, c2, p;
            cin >> c1 >> c2 >> p;
            c1--, c2--;
            g[c1][c2] = p;
            g[c2][c1] = p;
        }
        for (int k = 0; k<n; k++) {
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));
                }
            }
        }
        print(g);
        cin >> s >> d >> t;
        s--, d--;
        print(g[s][d]);
        print(g[d][s]);
        int ans = (90+g[s][d]-1)/g[s][d];
        printf("Scenario #%d\nMinimum Number of Trips = %d", c, ans);
        
        
        
        //!_______________________
        c++;
        cin >> n >> m;
        if (n)
            cout << "\n\n";
    }
}