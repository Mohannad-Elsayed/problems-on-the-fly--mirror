#define ONLINE_JUDGE
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
    using type = int;
    int N = -1, numSets;
    vector<type> root;
    vector<int> sze;
    bool is_initialized(){
        return ~N;
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
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
struct edge{
    int take;
    int f, t;
};
void solve(){
    int n, m, d; 
    cin >> n >> m;
    DSU dsu(n);
    vector<edge> edges(m+1);
    for (int i = 1; i<=m; i++){
        cin >> edges[i].f >> edges[i].t;
        edges[i].take = 1;
    }
    cin >> d;
    vector<int> deletes(d);
    each(i, deletes)
        cin >> i;
    
    // print(deletes);
    each(i, deletes){
        edges[i].take = 0;
    }

    // print(edges);
    // each(i, edges)
    //     cout << i.take << ' ' << i.f << ' ' << i.t << '\n';
    each(i, edges){
        if (i.take)
            dsu.union_set(i.f, i.t);
    }
    print(dsu.size());
    vector<int> ans(d);
    for (int i = d-1; i > -1; i--){
        ans[i] = dsu.size();
        dsu.union_set(edges[deletes[i]].f, edges[deletes[i]].t);
    }
    print(ans);
    each(i, ans)
        cout << i << ' ';


}