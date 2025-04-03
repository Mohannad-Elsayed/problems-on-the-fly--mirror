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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
class edge {
    public:
    int f, t;
    int w;
    edge() {}
    edge(int _f, int _t) : f(_f), t(_t), w(0) {}
    edge(int _f, int _t, int _w) : f(_f), t(_t), w(_w) {}
    edge(int _t) : f(-1), t(_t), w(0) {}
    bool operator < (const edge &e) const {
        return w < e.w;
    }
    bool operator > (const edge &e) const {
        return w > e.w;
    }
    friend string to_string(const edge e) {
        return "from: " + to_string(e.f) + " to: " + 
                to_string(e.t) + " w: " + to_string(e.w) + '\n';
    }
};

void solve() {
    int n, ans = 0; cin >> n;
    vector<vector<int>> mat(n, vector<int>(n)), g(n);
    vector<edge> edges;
    vector<int> vis(n);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> mat[i][j];
            if (i != j) {
                edges.emplace_back(i, j, mat[i][j]);
            }
        }
    }
    sort(all(edges));
    print(edges);
    function<bool(int, int)> connected = [&](int u, int v) -> bool {
        if (u == v) return true;
        vis[u] = 1;
        for (int ver : g[u]) {
            if (!vis[ver]) {
                if (connected(ver, v)) return true;
            }
        }
        return false;
    };

    auto connect = [&](int u, int v) {
        g[u].push_back(v);
    };

    each(e, edges) {
        print("curr ", e);
        print(g);
        vis = vector<int>(n, 0);
        if (!connected(e.f, e.t)) {
            print("not", e);
            connect(e.f, e.t);
            ans += e.w;
        }
    }
    print(g);
    cout << ans;
}