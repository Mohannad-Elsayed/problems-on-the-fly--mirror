#define ONLINE_JUDGE
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
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<31);
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
void printm(auto &v) {
    #ifndef ONLINE_JUDGE
    each(vv, v) {
        each(i, vv)
            cout << i << ' ';
        cout << '\n';
    }
    #endif
}
void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll l = 1, r = m, mid, res = -1;
    auto check = [&](ll ch) -> bool {
        ll here = (m - m/(ch+1)) * n;
        return here >= k;
    };
    while(l<=r) {
        mid = (l+r)>>1;
        if (check(mid)) {
            res = mid;
            r = mid-1;
        } else l = mid+1;
    }
    cout << res;










    // vector<int> indices;
    // set<int> ste;
    // for (int i = 0; i<m; i++) {
    //     indices.push_back(i);
    //     ste.insert(i);
    //     if (m-i-1 != i && !ste.count(m-i-1))
    //         indices.push_back(m-i-1), ste.insert(m-i-1);
    //     if (i+2 < m && !ste.count(i+2))
    //         indices.push_back(i+2), ste.insert(i+2);
    // }
    // print(indices);
    // vector<vector<int>> mat(n, vector<int>(m));
    // for (int c = 0; k > 0 && c < m; c++) {
    //     int i = indices[c];
    //     for (int row = 0; k > 0 && row < n; row++) {
    //         mat[row][i] = 1;
    //         k--;
    //         // print(row, i);
    //     }
    // }
    // printm(mat);
    // int mx = -1;
    // for (int i = 0; i<n; i++) {
    //     int c = 0;
    //     for (int j = 0; j < m; j++) {
    //         if (mat[i][j] == 1){
    //             c++;
    //         } else {
    //             chmax(mx, c);
    //             c = 0;
    //         }
    //     }
    //     if (c)
    //         chmax(mx, c);
    // }
    // cout << mx;
    
}