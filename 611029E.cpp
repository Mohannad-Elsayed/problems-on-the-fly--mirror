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
    // freopen("area.in", "r", stdin);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, m, p1, p2, ans = 1e9, mn1, mn2; string s, s1, s2; 
    cin >> n >> m;
    map<string, int> mp1, mp2; 
    for (int i = 0; i<n; i++) {
        cin >> s >> p1 >> p2;
        mp1[s] = p1;
        mp2[s] = p2;
    }
    vector<array<string, 2>> combin(m);
    for (int i = 0; i<m; i++) {
        cin >> s;
        s1.clear();
        s2.clear();
        p1 = 0;
        each(ch, s) {
            if (ch == '_') {
                p1 = 1;
                continue;
            }
            (p1 ? s2 : s1).push_back(ch); 
        }
        combin[i][0] = s1;
        combin[i][1] = s2;
    }
    // print(combin);
    set<string> vis;
    mn1 = 0;
    each(arr, combin) {
        if (!vis.count(arr[0])) {
            vis.insert(arr[0]);
            mn1 += mp1[arr[0]];
        }
        if (!vis.count(arr[1])) {
            vis.insert(arr[1]);
            mn1 += mp1[arr[1]];
        }
    }
    chmin(ans, mn1);
    for (auto [str, pr1] : mp1) {
        vis.clear();
        mn1 = mp2[str];
        
    }
}