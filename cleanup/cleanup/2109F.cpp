#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

struct Edge { int to; ll c; int rev; };
struct Dinic {
    int N;
    vector<vector<Edge>> G;
    vector<int> level, ptr;
    Dinic(int n): N(n), G(n), level(n), ptr(n) {}
    void addEdge(int u, int v, ll c){
        G[u].push_back({v,c,(int)G[v].size()});
        G[v].push_back({u,0,(int)G[u].size()-1});
    }
    bool bfs(int s, int t){
        fill(level.begin(), level.end(), -1);
        queue<int> q; q.push(s);
        level[s]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto &e:G[u]){
                if(level[e.to]<0 && e.c>0){
                    level[e.to]=level[u]+1;
                    q.push(e.to);
                }
            }
        }
        return level[t]>=0;
    }
    ll dfs(int u, int t, ll f){
        if(u==t||f==0) return f;
        for(int &i=ptr[u]; i<(int)G[u].size(); i++){
            auto &e=G[u][i];
            if(level[e.to]==level[u]+1 && e.c>0){
                ll w=dfs(e.to,t,min(f,e.c));
                if(w>0){
                    e.c-=w;
                    G[e.to][e.rev].c+=w;
                    return w;
                }
            }
        }
        return 0;
    }
    ll maxFlow(int s, int t){
        ll flow=0;
        while(bfs(s,t)){
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed=dfs(s,t,INF))
                flow+=pushed;
        }
        return flow;
    }
};

bool reachable(int n, int sx, int sy, int tx, int ty, int T,
               vector<vector<int>>& a) {
    if(a[sx][sy] > T) return false;
    vector<vector<bool>> vis(n, vector<bool>(n,false));
    queue<pair<int,int>> q;
    vis[sx][sy] = true;
    q.push({sx,sy});
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        if(x==tx && y==ty) return true;
        for(int d=0; d<4; ++d){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny] && a[nx][ny] <= T){
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    return false;
}

void extract_path(int n, int sx, int sy, int tx, int ty, int T,
                  vector<vector<int>>& a, vector<vector<bool>>& inP) {
    vector<vector<bool>> vis(n, vector<bool>(n,false));
    vector<vector<pair<int,int>>> par(n, vector<pair<int,int>>(n,{-1,-1}));
    queue<pair<int,int>> q;
    vis[sx][sy] = true;
    q.push({sx,sy});
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        if(x==tx && y==ty) break;
        for(int d=0; d<4; ++d){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny] && a[nx][ny] <= T){
                vis[nx][ny] = true;
                par[nx][ny] = {x,y};
                q.push({nx,ny});
            }
        }
    }
    int x = tx, y = ty;
    while(x != -1){
        inP[x][y] = true;
        auto p = par[x][y];
        x = p.first; y = p.second;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) {
        int n, r; ll k;
        cin >> n >> r >> k;
        --r;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
        vector<string> c(n);
        for(int i=0;i<n;i++) cin >> c[i];

        int lo = 0, hi = 1e6+5, disM;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(reachable(n, 0, 0, r, n-1, mid, a)) hi = mid;
            else lo = mid + 1;
        }
        disM = lo;

        vector<vector<bool>> inP(n, vector<bool>(n,false));
        extract_path(n, 0, 0, r, n-1, disM, a, inP);

        lo = 0; hi = 1e6+5;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(reachable(n, n-1, 0, r, n-1, mid, a)) hi = mid;
            else lo = mid + 1;
        }
        int disF0 = lo;

        int L = disF0, R = disM + k;
        while(L < R) {
            int mid = (L + R + 1) / 2;
            int cells = n*n;
            int V = 2*cells + 2;
            int S = V-2, Tt = V-1;
            Dinic mf(V);
            auto id = [&](int x,int y){ return x*n + y; };
            for(int i=0;i<n;i++) for(int j=0;j<n;j++){
                int idx = id(i,j);
                ll cap = (c[i][j]=='0' || inP[i][j]) ? INF : max<ll>(0, mid - a[i][j]);
                mf.addEdge(2*idx, 2*idx+1, cap);
                int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
                for(int d=0; d<4; ++d){
                    int ni=i+dx[d], nj=j+dy[d];
                    if(ni>=0 && ni<n && nj>=0 && nj<n)
                        mf.addEdge(2*idx+1, 2*id(ni,nj), INF);
                }
            }
            int sidx = id(n-1,0), tidx = id(r,n-1);
            mf.addEdge(S, 2*sidx, INF);
            mf.addEdge(2*tidx+1, Tt, INF);
            ll need = mf.maxFlow(S, Tt);
            if(need <= k) L = mid;
            else R = mid-1;
        }

        cout << disM << " " << L << '\n';
    }
    return 0;
}
