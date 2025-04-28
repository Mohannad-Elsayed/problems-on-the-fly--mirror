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
int LIMIT = 6e4+100;
vector<int> sieve(LIMIT + 1), cntdivs(LIMIT+1);
void precompute(){
    for (int x = 2; x <= LIMIT; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= LIMIT; u += x) {
            if (sieve[u]) continue;
            sieve[u] = x;
        }
    }
}
int countDivisors(int x) {
    int divisors = 1;
    while (sieve[x]) {
        int p = sieve[x];
        int cnt = 0;
        while (x % p == 0){
            x /= p;
            cnt++;
        }
        divisors *= cnt + 1;
    }
    if (x > 1) divisors *= 2;
    return divisors;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    precompute();
    for (int i = 2; i < LIMIT; i++) 
        cntdivs[i] = countDivisors(i)-1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int bgcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
int MOD = 1e9+7;
void add(int &a, int b) {
    a += b;
    while (a >= MOD)
        a -= MOD;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n), nex(n);
    getv(v);
    for (int i = 0; i < n; i++) {
        // v[i], 
        // v[j] != v[i], 
        // i -> j-1 = j,
        // i = j-1
        int j;
        for (j = i+1; j < n; j++) {
            if (v[j] != v[i])
                break;
        }
        for (int k = i; k <= j && k < n; k++) {
            nex[k] = j;
        }
        i = j-1;
    }
    print(nex);
    int ans = 0, gg = 0;
    for (int i = 0; i < n; i++) {
        gg = 0;
        // add(ans, cntdivs[gg]);
        for (int j = i; j < n; j = nex[j]) {
            print(j, (nex[j]-j));
            gg = bgcd(gg, v[j]);
            print(i, j, gg);
            if (gg == 1)
                break;
            add(ans, cntdivs[gg]*(nex[j]-j));
        }
    }
    cout << ans;
}

// 4 4 4 4 8 8 8
// i = 1
// 1 -> 4
// i = 2
