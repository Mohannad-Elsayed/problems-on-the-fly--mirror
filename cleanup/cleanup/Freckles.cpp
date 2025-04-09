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
    cout << fixed << setprecision(2);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}


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


void solve() {
    int n; cin >> n;
    double x, y;
    vector<pair<double, double>> gt(n); // id, x, y

    for (int i = 1; i<=n; i++)
        cin >> gt[i-1].first >> gt[i-1].second;
    
    vector<edge> g;
    for (int i = 1; i<=n; i++) {
        for (int j = i+1; j<=n; j++) {
            double distance = sqrt((gt[i-1].first - gt[j-1].first) * (gt[i-1].first - gt[j-1].first) + (gt[i-1].second - gt[j-1].second) * (gt[i-1].second - gt[j-1].second));
            g.emplace_back(edge(i, j, distance));
            g.emplace_back(edge(j, i, distance));
        }
    }
    sort(all(g));
    print(g);
    DSU d(n);
    double ans = 0;
    for (auto [i, j, w] : g)
        if (d.union_set(i, j))
            ans += w;
    cout << ans << '\n';
}