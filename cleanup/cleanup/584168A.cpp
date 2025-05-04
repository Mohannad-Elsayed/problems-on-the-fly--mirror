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
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll

void solve() {
    string s, curr, ans; cin >> s;
    int n = s.size();
    int limit = 1ll << n;
    char mxmex = 'a', currmex;
    set<char> ste, stec;
    for (char i = 'a'; i <= 'z'; i++)
        ste.insert(i);
    for (int mask = 1; mask < limit; mask++) {
        curr.clear();
        for (int i = 0; i < n; i++)
            if (mask >> i & 1)
                curr.push_back(s[i]);
        stec = ste;
        each(ch, curr)
            stec.erase(ch);
        currmex = *stec.begin();
        if (currmex > mxmex || (currmex == mxmex && curr > ans)) {
            mxmex = currmex;
            ans = curr;
        }
    }
    cout << ans;
}