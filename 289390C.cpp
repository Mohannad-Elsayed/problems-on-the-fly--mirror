// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
void solve();
class DSU {
    private:
    int N = 0, numSets;
    vector<int> root;
    bool is_initialized(){
        return N;
    }
    void make_set(int u){
        root[u] = u;
        sze[u] = 1;
        pts[u] = 0;
    }
    public:
    vector<ll> pts;
    vector<int> sze;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int _n){
        N = _n + 100;
        root.resize(N);
        sze.resize(N);
        pts.resize(N);
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


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
void solve(){
    int n, q;
    cin >> n >> q;
    DSU d(n);
    while(q--){
        string k; 
        int a, b; cin >> k >> a;
        if (k[0] != 'g'){
            cin >> b;
        }
        if (k[0] == 'g'){
            cout << d.pts[a] << '\n';
        } else if (k[0] == 'a') {
            int u = d.find_set(a);
            d.pts[u] += b * d.size_set(u);
        } else {
            d.union_set(a, b);
        }
    }
}