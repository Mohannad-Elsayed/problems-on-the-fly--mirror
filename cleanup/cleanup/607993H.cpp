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
void stress() {
    int n = 10;
    vector<vector<int>> allsets, newsets;
    vector<int> newsetv, allsetv;
    for (int i = 1; i <= n; i++) {
        vector<vector<int>> newsets;
        each(ste, allsets) {
            if (ste.front() >= ste.size()+1) {
                newsets.push_back(ste);
                newsets.back().push_back(i);
            }
        }
        each(ste, newsets)
            allsets.push_back(ste);
        allsets.push_back(vector<int>(1, i));
        newsetv.push_back(newsets.size()+1);
        allsetv.push_back(allsets.size());
        // print(i, allsets.size());
        // print(i, newsets.size());
        // print(newsets);
    }
    print(allsetv);
    print(newsetv);
    // exit(0);
}
int N = 1e5+100;
vector<int> ans(N), fib(N);
int mod = 1e9+7;
void pre() {
    fib[0] = 1, fib[1] = 2;
    for (int i = 2; i < N; i++) {
        fib[i] = fib[i-1] % mod + fib[i-2] % mod;
        fib[i] %= mod;
        // if (i < 100)
        //     print(i, fib[i]);
    }
    ans[1] = 1;
    for (int i = 2; i < N; i++) {
        ans[i] = ans[i-1]%mod + fib[i-2]%mod;
        ans[i] %= mod;
    }
    for (int i = 0; i < 10; i++) 
        print(i, ans[i]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("area.in", "r", stdin);
    // stress();
    pre();
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

int mod_inv(int x, int mod) {
    return mod_exp(x, mod - 2, mod);
}

int mod_comb(int n, int k, int mod) {
    if (k > n || k < 0) return 0;
    int num = 1, denom = 1;
    for (int i = 0; i < k; i++) {
        num = (1LL * num * (n - i)) % mod;
        denom = (1LL * denom * (i + 1)) % mod;
    }
    return (1LL * num * mod_inv(denom, mod)) % mod;
}

int sum_combinations(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + mod_comb(n - i + 1, i, mod)) % mod;
    }
    return result;
}
void solve() {
    int n; cin >> n;
    // cout << ans[n];
    cout << sum_combinations(n);
}