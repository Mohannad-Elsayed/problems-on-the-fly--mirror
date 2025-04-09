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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    getv(v);
    int mx = -1;
    string mxstring, currstring;
    vector<vector<int>> dp(2, vector(n, -1ll));
    function<void(int, int, int)> rec = 
        [&](int i = 0, int t = 0, int curr = 0) {
            if (i == n) {
                if (curr > mx) {
                    mx = curr;
                    mxstring = currstring;
                }
                return;
            }
            if (~dp[t][i]) {

            }
            int mxansrec = 0;
            currstring.push_back('O');
            mxansrec = rec(i+1, 0ll, curr+v[i]);
            currstring.pop_back();
            if (!t) {
                currstring.push_back('M');
                rec(i+1, 1ll, curr+2*v[i]);
                currstring.pop_back();
            }
        };
    rec(0, 0, 0);
    print(mx);
    print(mxstring);
}