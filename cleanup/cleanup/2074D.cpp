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
#define int ll
void solve() {
    int ans = 0;
    int n, m; 
    cin >> n >> m;
    map<int, int> mp; // point - max y
    vector<int> pos(n), rad(n);
    each(i, pos)
        cin >> i;
    each(i, rad)
        cin >> i;
    print(pos);
    print(rad);
    for (int i = 0; i<n; i++) {
        for (int ci = pos[i]-rad[i]; ci <= pos[i]+rad[i]; ci++) {
            int curr = sqrtl(rad[i]*rad[i] - (ci-pos[i])*(ci-pos[i]));
            print(ci, curr);
            mp[ci] = max(curr, mp[ci]);
        }
    }
    print(mp);
    for (auto [x, y] : mp)
        ans += y*2+1;
    cout << ans;
}