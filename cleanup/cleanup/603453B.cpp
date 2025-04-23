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

vector<bool> prime;
int N = 1e7+10;
vector<int> pfx;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    prime.assign(maximum + 1, true);
    pfx.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    pfx[1] = 1;
    for (int p = 2; p <= maximum; p++) {
        if (prime[p]) {
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                }
        }
        for (ll i = p; i < maximum; i *= p)
            pfx[i] = 1;
    }
    for (int i = 0; i<100; i++) {
        
    }
    for (int i = 1; i<N; i++)
        pfx[i] += pfx[i-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    sieve(N);
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int l, r; 
    cin >> l >> r;
    cout << pfx[r] - pfx[l-1];
}