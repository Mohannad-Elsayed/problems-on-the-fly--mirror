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
    cout << fixed << setprecision(3);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
double dis(int x1, int x2, int y1, int y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

class edge {
    public:
    int f, t;
    double w;
    edge() {}
    edge(int _f, int _t) : f(_f), t(_t), w(0) {}
    edge(int _f, int _t, double _w) : f(_f), t(_t), w(_w) {}
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


class DSU {
    private:
    int N = 0, numSets;
    vector<int> root;
    vector<int> sze;
    bool is_initialized(){
        return N;
    }
    void make_set(int u){
        assert(is_initialized());
        root[u] = u;
        sze[u] = 1;
    }
    public:
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int _n){
        N = _n + 100;
        root.resize(N);
        sze.resize(N);
        numSets = _n;
        for (int i = 0; i<N; i++)
            make_set(i);
    }
    int find_set(int u){
        assert(is_initialized());
        while (u != root[u]) 
            u = root[u] = root[root[u]];
        return u;
    }
    bool union_set(int u, int v){
        assert(is_initialized());
        u = find_set(u), 
        v = find_set(v);
        if (u != v){
            if (sze[u] > sze[v])
                swap(u, v); // u is smaller, then root[u] = v
            root[u] = v; // rep of the smaller is the bigger representative 
            sze[v] += sze[u]; // size of the bigger is increased
            return --numSets;
        }
        return false;
    }
    bool same_set(int u, int v){
        assert(is_initialized());
        return find_set(u) == find_set(v);
    }
    int size_set(int u){
        return sze[find_set(u)];
    }
    int size(){
        return numSets;
    }
};

void solve() {
    int n, c = 1; cin >> n;
    double ans;
    while(n) {
        vector<pair<int, int>> points(n); // x, y
        each(p, points)
            cin >> p.first >> p.second;
        vector<vector<double>> adj(n, vector<double>(n));
        auto printg = [&]() {
            each(vv, adj) {
                each(i, vv)
                    cout << i << ' ';
                cout << '\n';
            }
        };
        // vector<edge> edges;
        // DSU d(n);
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                adj[i][j] = dis(points[i].first, points[j].first, points[i].second, points[j].second);
                // edges.emplace_back(i, j, adj[i][j]);
            }
        }
        // sort(all(edges));
        // each(e, edges) {
        //     if (d.union_set(e.f, e.t))
        //         ans = e.w;
        //     if (d.same_set(0, 1))
        //         break;
        // }
        for (int i = 0; i<n; i++)
            adj[i][i] = 0;

        for (int k = 0; k<n; k++)
            for (int i = 0; i<n; i++)
                for (int j = 0; j<n; j++)
                    adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));

        // printg();
        ans = adj[0][1];

        cout << "Scenario #" << c << "\nFrog Distance = " << ans << "\n\n";
        cin >> n;
        c++;
    }
}