#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC optimize ("Ofast")
    // #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
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
// #define int ll
void solve() {
    int n; cin >> n;
    vector<vector<ll>> allteams(n, vector<ll>());
    vector<int> uid(n), skill(n);
    each(i, uid)
        cin >> i;
    each(i, skill)
        cin >> i;

    for (int i = 0; i<n; i++)
        allteams[uid[i]-1].push_back(skill[i]);
    vector<ll> ans(n+1);
    int sz;
    for (int i = 0; i < n; i++) {
        sort(rall(allteams[i]));
        sz = (int)allteams[i].size();
        for (int j = 1; j < sz; j++)
            allteams[i][j] += allteams[i][j-1];
        
        for (int k = 1; k <= sz; k++) {
            ans[k] += allteams[i][(sz/k*k)-1];
        }
    }
    for (int k = 1; k <= n; k++)
        cout << ans[k] << ' ';
}