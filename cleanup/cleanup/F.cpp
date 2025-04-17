// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("cleanup/debug.h not found, or ONLINE_JUDGE defined.")
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
    int n, m, t, a, b, x, val = 0; 
    cin >> n >> m;
    for (int i = 0; i<30; i++)
        val |= (1 << i);
    vector<int> arr(n, val); 
    vector<set<int>> vste(n);
    vector<tuple<int, int, int>> vp;
    while(m--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> x; 
            vste[--a].insert(x);
        } else {
            cin >> a >> b >> x;
            arr[--a] ^= x;
            arr[--b] ^= x;
            vp.emplace_back(a, b, x);
        }
    }
    // print(arr);
    for (int i = 0; i<n; i++)
        if (vste[i].count(arr[i]))
            kill("1NO");
    for (auto [a, b, x] : vp)
        if ((arr[a] ^ arr[b]) != x) {
            // print(a, b, x);
            // print(arr[a], arr[b]);
            // print(arr[a]^arr[b]);
            kill("NO");
        }
    cout << "YES\n";
    each(i, arr)
        cout << i << ' ';
}