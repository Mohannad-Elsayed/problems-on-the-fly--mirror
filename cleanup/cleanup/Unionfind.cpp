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
int pre(){
    
    //________________________
    return 0;
}
const int N = 2e5 + 10;
const int Q = 2e5 + 10;

class DSU {
    private:
    using type = int;
    int N;
    vector<type> root;
    vector<int> sze;
    public:
    DSU(int n) {
        N = n;
        root.resize(n);
        sze.resize(n);
        for (int i = 0; i<n; i++)
            make_set(i);
    }
    void make_set(int u){
        root[u] = u;
        sze[u] = 1;
    }
    int find_set(int u){
        if (root[u] == u)
            return u;
        return root[u] = find_set(root[u]);
    }
    void union_set(int u, int v){
        u = find_set(u), 
        v = find_set(v);
        if (u != v){
            if (sze[u] > sze[v])
                swap(u, v); // u is smaller, then root[u] = v
            root[u] = v; // rep of the smaller is the bigger representative 
            sze[v] += sze[u]; // size of the bigger is increased
        }
    }
    bool same_set(int u, int v){
        return find_set(u) == find_set(v);
    }
};

vector<char> ans(N);
int idx = 0;

int solve(){
    int n, q; 
    scanf("%d%d", &n, &q);
    DSU dsu(n);
    for (int i = 0; i<n; i++)
        dsu.make_set(i);
    print(n, q);
    while (q--){
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if (t){
            ans[idx++] = dsu.same_set(a, b);
        } else {
            dsu.union_set(a, b);
        }
    }
    for (int i = 0; i<idx; i++)
        printf("%d\n", ans[i]);
    //________________________
    return 0;
}