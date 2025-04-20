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
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

// …existing includes & helpers…

void solve() {
    const ll INF = LLONG_MAX/4;
    int n;
    cin >> n;
    vector<vector<ll>> h(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> h[i][j];
    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    // compute forbidden masks as before
    vector<int> forbidX(n-1, 0), forbidY(n-1, 0);
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j < n; j++) {
            ll d = h[i+1][j] - h[i][j];
            if (d >= -1 && d <= 1) forbidX[i] |= 1 << (d+1);
        }
    for (int j = 0; j + 1 < n; j++)
        for (int i = 0; i < n; i++) {
            ll d = h[i][j+1] - h[i][j];
            if (d >= -1 && d <= 1) forbidY[j] |= 1 << (d+1);
        }
    for (int i = 0; i + 1 < n; i++) {
        if (forbidX[i] == 0b111) kill(-1);
        if (forbidY[i] == 0b111) kill(-1);
    }

    auto solveChain = [&](const vector<int>& forbid,
                          const vector<ll>& cost) {
        int N = n * 2 + 1;
        int S = n*2;
        vector<vector<pair<int,ll>>> adj(N);
        auto id = [&](int i, int bit){ return i*2 + bit; };
        // source → (0,0/1)
        adj[S].push_back({ id(0,0), 0 });
        adj[S].push_back({ id(0,1), cost[0] });
        // transitions
        for (int i = 0; i + 1 < n; i++) {
            for (int cur = 0; cur < 2; cur++) {
                for (int nxt = 0; nxt < 2; nxt++) {
                    int d = cur - nxt, b = d+1;
                    if (!(forbid[i] & (1<<b))) {
                        adj[id(i,cur)].push_back(
                          { id(i+1,nxt), nxt? cost[i+1] : 0 });
                    }
                }
            }
        }
        // Dijkstra
        vector<ll> dist(N, INF);
        priority_queue<pair<ll,int>,
                       vector<pair<ll,int>>,
                       greater<>> pq;
        dist[S]=0; pq.push({0,S});
        while(!pq.empty()) {
            auto [d,u]=pq.top(); pq.pop();
            if (d>dist[u]) continue;
            for (auto &e: adj[u]) {
                int v=e.first; ll w=e.second;
                if (d+w<dist[v]) {
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return min(dist[id(n-1,0)], dist[id(n-1,1)]);
    };

    ll bestX = solveChain(forbidX, a);
    if (bestX >= INF) kill(-1);
    ll bestY = solveChain(forbidY, b);
    if (bestY >= INF) kill(-1);
    cout << (bestX + bestY);
}