#define ONLINE_JUDGE
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
void solve() {
    int n, cntvis = 0, ans = 0; 
    cin >> n;
    vector<int> v(n), vis(n);
    map<int, set<int>, greater<int>> mp;
    getv(v);
    for (int i = 0; i < n; i++) {
        mp[v[i]].insert(i);
    }
    print(mp);
    for (auto [e, idxs] : mp) {
        if (cntvis == n)
            break;

        each(idx, idxs) {
            if (!vis[idx]) {
                print("here");
                vis[idx] = 1; 
                cntvis++;
                ans++;
            }
            if (idx > 0 && v[idx-1] <= e) {
                int curridx = idx-1;
                while(curridx >= 0 && v[curridx] <= v[curridx+1] && !vis[curridx]) {
                    vis[curridx] = 1;
                    mp[v[curridx]].erase(curridx);
                    cntvis++;
                    curridx--;
                }
            }
            if (idx+1 < n && v[idx+1] <= e) {
                int curridx = idx+1;
                while(curridx < n && v[curridx] <= v[curridx-1] && !vis[curridx]) {
                    vis[curridx] = 1;
                    mp[v[curridx]].erase(curridx);
                    cntvis++;
                    curridx++;
                }
            }
            // if (idx+1 < n)
            //     vis[idx+1] = 1, cntvis++;
            print(e, idx);
            print(vis);
        }
    }
    cout << ans;
}