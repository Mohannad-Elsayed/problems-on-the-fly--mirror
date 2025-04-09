// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
void solve();
#undef RAND_MAX
#define RAND_MAX int(1e9)
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    srand(time(0));
    int tt = 1;
    // cout << RAND_MAX;
    // exit(0);
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int check(int a, int b, int c = 0) {
    c = a^b;
    return (a+b > c && a+c > b && b+c > a);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, int(1e9));
void solve() {
    int n; cin >> n;
    for (int iter = 0; iter < 200; iter++) {
        int c = uid(rng)%n + 1;
        if (c == n)
            continue;
        if (check(n, c))
            kill(c);
    }
    cout << -1;
}