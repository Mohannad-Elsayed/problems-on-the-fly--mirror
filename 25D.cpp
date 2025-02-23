#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << (x), 0;
#define killn(x) return cout << (x) << '\n', 0;

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

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
        N = n + 100;
        root.resize(N);
        sze.resize(N);
        numSets = n;
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

int pre(){
    
    //________________________
    return 0;
}
int solve(){
    int n; cin >> n;
    DSU city(n);
    vector<pair<int, int>> not_con, alr_con;
    for (int i = 1; i<n; i++){
        int u, v; 
        cin >> u >> v;
        if (city.same_set(u, v))
            alr_con.push_back({u, v});
        else city.union_set(u, v);
    }
    cout << alr_con.size() << '\n';
    int f = -1;
    for (f = 1; f<=n; f++)
        if (f == city.find_set(f))
            break;
    for (int i = f+1; i <= n; i++){
        if (i == city.find_set(i)){
            cout << alr_con.back().first << ' ' << alr_con.back().second << ' ' << f << ' ' << i << '\n';
            alr_con.pop_back();
        }
    }

    //________________________
    return 0;
}