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


int main() {
    int n; cin >> n;
    print(n);
    vector<int> nums(n);
    getv(nums);
    int total = 1 << n;
    int ans = 0;
    for (int i = 0; i < total; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) 
            if ((i >> j) & 1)
                cur ^= nums[j], print(cur, i, j);
        
        ans += cur;
    }
    print(ans);
    
    return 0;
}

void solve() {
    int n; cin >> n;
    DSU d(n);
    vector<edge> edges(n-1);
    each(i, edges)
        cin >> i.f >> i.t >> i.w;
    sort(all(edges));
    ll ans = 0;
    each(e, edges) {
        ans += 1LL * e.w * d.size_set(e.f) * d.size_set(e.t);
        d.union_set(e.f, e.t);
    }
    cout << ans;
}