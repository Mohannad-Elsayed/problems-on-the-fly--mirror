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
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
bool isPrime(int n) {
    if (n <= 1)
        return false;
    
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int primesc = sizeof(primes) / sizeof(primes[0]);
    for (int i = 0; i<primesc; i++) {
        if (n == primes[i])
            return true;
        if (n % primes[i] == 0)
            return false;
    }
    
    int arr[] = {1, 7, 11, 13, 17, 19, 23, 29};
    int arrc = sizeof(arr)/sizeof(arr[0]);
    // 30k + 1, 30k + 7
    for (int i = 30; i * i <= n; i += 30)
        for (int j = 0; j < arrc; j++)
            if (n % (i+arr[j]) == 0)
                return false;

    return true;
}
void solve() {
    int n; 
    cin >> n;
    if (n < 5)
        kill(-1);
    if (isPrime(n-2)) {
        cout << 2 << ' ' << n-2;
        return;
    }
    kill(-1);
}