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
    int n, m, q, t, w1, w2; cin >> n >> m >> q;
    map<string, int> id; // str, id
    string s, s2;
    DSU syn(n), ant(n);
    for (int i = 0; i<n; i++) {
        cin >> s;
        id[s] = i;
    }
    for (int i = 0; i<m; i++) {
        cin >> t >> s >> s2;
        w1 = id[s];
        w2 = id[s2];
        if (t == 1) {
            if (ant.same_set(w1, w2)) {
                cout << "NO\n";
            } else syn.union_set(w1, w2), cout << "YES\n";
        }
        if (t == 2) {
            if (syn.same_set(w1, w2)) {
                cout << "NO\n";
            } else ant.union_set(w1, w2), cout << "YES\n";
        }
    }

}