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
// #define ONLINE_JUDGE
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
vector<int> parent(256);
void make_set(int u){
    parent[u] = u;
}
int find_set(int u){
    if (parent[u] == u)
        return u;
    return parent[u] = find_set(parent[u]);
}
bool union_set(int s1, int s2){
    int ps1 = find_set(s1), 
        ps2 = find_set(s2);
    if (ps1 != ps2){
        parent[ps2] = ps1;
        return true;
    }
    return false;
}
int solve(){

    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<pair<char, char>> ans;
    for (int i = 0; i < 256; i++)   
        make_set(i);
    for (int i = 0; i<n; i++){
        if (union_set(a[i], b[i]))
            ans.push_back(make_pair(a[i], b[i]));
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        cout << x << ' ' << y << '\n';
    
    //________________________
    return 0;
}