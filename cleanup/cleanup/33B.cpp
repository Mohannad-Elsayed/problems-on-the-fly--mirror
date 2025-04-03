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
uniform_int_distribution<> uid(1, 1ll<<30);
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
const int OO = 1e9;
void solve() {
    string s, t; int n;
    cin >> s >> t >> n;
    if (s.size() != t.size())
        kill(-1);
    each(ch, s)
        ch -= 'a';
    each(ch, t)
        ch -= 'a';

    vector<vector<int>> g(26, vector<int>(26, OO));
    for (int i = 0; i<26; i++)
        g[i][i] = 0;

    while(n--) {
        char a, b; 
        int w;
        cin >> a >> b >> w;
        a-='a', b-='a';
        g[a][b] = min(w,g[a][b]);
        // g[b][a] = w;
    }
    for (int k = 0; k<26; k++) 
        for (int i = 0; i<26; i++) 
            for (int j = 0; j<26; j++)
                chmin(g[i][j], g[i][k]+g[k][j]);
    print(g['a'-'a']['y'-'a']);
    n = s.size();
    ll ans = 0;
    string res(n, '-');
    for (int i = 0; i<n; i++) {
        int foundchar,localans=OO;
        for (int c = 0; c<26; c++) {
            if (g[s[i]][c] + g[t[i]][c] < localans) 
                chmin(localans, g[s[i]][c] + g[t[i]][c]), foundchar=c;
        }
        if (localans == OO) 
            kill(-1);
        ans += localans;
        res[i]=foundchar+'a';
    }
    cout << ans << '\n' << res;
}