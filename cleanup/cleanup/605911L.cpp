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
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("crypto.in", "r", stdin);
    freopen("math.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void stress() {
    int N = 30;
    vector<int> monsters(N+10), avgs(N+10);
    monsters[1] = avgs[1] = 1;
    for (int i = 2; i<N; i++) {
        int sumi_1 = accumulate(monsters.begin(), monsters.begin()+i, 0ll);
        // print(i, sumi_1);
        // print(sumi_1/(i-1));
        monsters[i] = sumi_1;
        avgs[i] = 2 * (sumi_1/(i-1));
        monsters[i] += avgs[i];
    }
    for (int i = 2; i < N; i++) {
        monsters[i] += monsters[i-1];
        int sumi_1 = accumulate(monsters.begin(), monsters.begin()+i, 0ll);
        int mi = monsters[i];
        int gi = avgs[i];
        int pi = pow(2, 3+i);
        print(i, mi, gi);
        print(i, sumi_1);
        // print(i, pi);
    }
}
int mod = 1e9+7;
ll fp(ll b, ll n, ll MOD = mod) {
    b %= MOD;
    ll s = 1;
    while (n) {
        if (n & 1) s = s * b % MOD;
        b = b * b % MOD;
        n >>= 1;
    }
    return s;
}
void solve() {
    // stress();
    int n; 
    cin >> n;
    cout << ((n%mod)*fp(2, n-1))%mod;
}