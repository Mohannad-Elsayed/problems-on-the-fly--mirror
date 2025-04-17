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
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

class DSU {
    public:
    int N = 0, numSets;
    vector<int> root, subs;
    vector<int> sze;
    bool is_initialized(){
        return N;
    }
    void make_set(int u){
        assert(is_initialized());
        root[u] = subs[u] = u;
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
        subs.resize(N);
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
        int tu = u, tv = v;
        u = find_set(u), 
        v = find_set(v);
        if (u != v){
            if (sze[u] > sze[v])
                swap(u, v); // u is smaller, then root[u] = v
            root[u] = v; // rep of the smaller is the bigger representative 
            sze[v] += sze[u]; // size of the bigger is increased
            subs[tu] = subs[tv];
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

const int N = 5e5;
DSU d(N);

void solve() {
    int n; cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
        int t, a, b = 0; 
        cin >> t >> a;
        if (t == 2)
            cin >> b;
        v.emplace_back(vector<int>{t, a, b});
    }
    print(v);
    vector<int> ans;
    reverse(all(v));
    each(vv, v) {
        if (vv.front() == 1) {
            ans.push_back(d.subs[vv[1]]);
        } else {
            if (vv[1] != vv[2])
                d.union_set(vv[1], vv[2]);
        }
    }
    reverse(all(ans));
    print(ans);
    each(i, ans)
        cout << i << ' ';
}