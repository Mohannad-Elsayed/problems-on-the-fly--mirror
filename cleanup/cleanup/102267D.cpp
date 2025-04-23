#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define nl <<'\n'
#define vll vector<ll>
#define vi vector<int>
#define pb(x) push_back(x)
#define dbg(x) cout<<#x<<" = "<<x<<nl
#define sp <<' '
#define get(n, t) get<n>(t)
#define geti(n, i, t) get<n>(t)=i
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define ll long long
#define int long long
#define see(v) for(auto &i : v)cin>>i
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define f first
#define ss second
#define pc(x) __builtin_ctz(x)
#define  no cout<<"NO" nl;
#define  yes cout<<"YES" nl;
#define pii pair<int , int>
#define vpii vector<pii>
//Orderd set
template<class T> using ordered_set = tree<T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;
//multi ordered set
template<class T> using multi_ordered_set = tree<T, null_type, less_equal<T>,
        rb_tree_tag, tree_order_statistics_node_update>;
double sTime;

void File() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sTime = clock();
#endif
}

void endFile() {
#ifndef ONLINE_JUDGE
    double eTime = clock();
    double TIME_TAKEN = double(eTime - sTime) / double(CLOCKS_PER_SEC);
    cout << "\n//Time taken = " << fixed << std::setprecision(5) << TIME_TAKEN << "ms\n";
#endif
}
/*
 * __builtin_clz(x): the number of zeros at the beginning of the number
 * __builtin_ctz(x): the number of zeros at the end of the number
 * __builtin_parity(x): the parity (even or odd) of the number of ones
 */
//##############################################################################################################
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char di[] = {'D', 'R', 'U', 'L'};

//const int N = 1e3 + 1;
//const ll mod = 1e9 + 7;
int grid[13][13];
bool vis[13][13];
string path;
string ans;
void bfs(int r , int c){
    if(grid[r][c] == 1){
        ans = path;
        return;
    }
    vis[r][c] = true;
    for(int i = 0; i < 4; i++){
        int gox = r + dx[i];
        int goy = c + dy[i];
        if(gox >= 1 && goy >= 1 && gox <= 12 && goy <= 12 && grid[gox][goy] != -1 && !vis[gox][goy]){
            path.push_back(di[i]);
            bfs(gox, goy);
            path.pop_back();
        }
    }
    
}
vector<pair<int , int>>vp;
void pre(){
    grid[3][3] = 1;
    grid[3][10] = 1;
    grid[10][3] = 1;
    grid[10][10] = 1;
    vp.push_back({3 , 3});
    vp.push_back({3 , 10});
    vp.push_back({10 , 3});
    vp.push_back({10 , 10});

    grid[10][2] = -1;
    grid[9][2] = -1;
    grid[9][3] = -1;
    grid[10][11] = -1;
    grid[9][11] = -1;
    grid[9][10] = -1;


    grid[7][6] = -1;
    grid[7][7] = -1;
    grid[6][6] = -1;
    grid[6][7] = -1;

}
void solve() {
    int r, c; cin>>r>>c;
    int mn = 1e9;

    if(mn == 0){
        cout<<0 nl;
        return;
    }
    bfs(r , c);

    cout<<ans.length() nl;
    cout<<ans nl;


}

signed main() {
    fastio
    //File();
    pre();
    int t = 1;
    cin >> t;
    int T = t;
    while (t--) {
        solve();
        for(int i = 0 ; i <=12;i++){
            for(int j = 0; j <= 12; j++) vis[i][j] = false;
        }
    }
    //endFile();

    return 0;
}