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

void solve() {
    int n, m, u, v; cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<int> vis(n+1), ans(n+1), outdeg(n+1);
    while(m--) {
        cin >> u >> v;
        // v -> u
        // g[v].push_back(u);
        g[v].push_back(u);
        outdeg[u]++;
    }
    int c = n;
    set<int, greater<int>> q;
    for (int i = 1; i <= n; i++) 
        if (!outdeg[i])
            q.insert(i);
    while(q.size()) {
        int u = *q.begin();
        q.erase(q.begin());
        ans[u] = c--;
        each(v, g[u]) {
            outdeg[v]--;
            if (!outdeg[v])
                q.insert(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}