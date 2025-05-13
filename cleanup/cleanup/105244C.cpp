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
    int n, Energy, Time;
    cin >> n >> Energy >> Time;
    vector<array<int, 3>> elements(n); // value, energy, time
    int cache[101][101][101];
    memset(cache, -1, sizeof(cache));
    vector<int> ans;
    each(i, elements)
        cin >> i[0] >> i[1] >> i[2];

    function<int(int, int, int)> rec = 
            [&](int idx, int re, int rt) -> int { 
                if (idx == n)
                    return 0;
                int& ret = cache[idx][re][rt];
                if (~ret)
                    return ret;
                int a = rec(idx+1, re, rt), b = -1e9;
                if (re >= elements[idx][1] && rt >= elements[idx][2]) {
                    b = rec(idx+1, re - elements[idx][1], rt - elements[idx][2]) + elements[idx][0];
                }
                return ret = max(a, b);
    };
    function<void(int, int, int)> build = 
        [&](int idx, int re, int rt) -> void {
            if (idx == n)
                return;
            int a = rec(idx+1, re, rt), b = -1e9;
            if (re >= elements[idx][1] && rt >= elements[idx][2]) {
                b = rec(idx+1, re - elements[idx][1], rt - elements[idx][2]) + elements[idx][0];
            }
            if (b > a) {
                ans.push_back(idx+1);
                build(idx+1, re - elements[idx][1], rt - elements[idx][2]);
            } else 
                build(idx+1, re, rt);
    };
    // int mxans = rec(0, Energy, Time);
    build(0, Energy, Time);
    cout << rec(0, Energy, Time) << '\n';
    each(i, ans)
        cout << i << ' ';
}