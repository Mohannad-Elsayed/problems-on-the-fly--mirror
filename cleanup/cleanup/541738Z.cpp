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
template<class T> void getv(T& v) {each(i, v)cin>>i;}
#define int ll
const int MOD = (int)1e9+7;

int b(int n) {
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (__builtin_popcount(i ^ j) == 1) {
                cnt++;
                if (cnt >= MOD)
                    cnt -= MOD;
            }
        }
    }
    return cnt;
}

ll count1(ll X, int k) {
    if (X < 0) return 0;
    ll cycle = 1LL << (k + 1);
    ll half = 1LL << k;
    ll full = (X + 1) / cycle;
    ll res = full * half;
    ll rem = (X + 1) % cycle;
    res += max(0LL, rem - half);
    return res;
}

// Optimized `o()` function using previous values efficiently
int o(int n) {
    ll ans = 0;
    vector<ll> ones_cache(64, -1); // Cache to store results of `count1(n, k)`
    
    for (int k = 0; (1LL << k) <= n; k++) {
        ll p = 1LL << k;
        ll totalCount = (n - p + 1);
        ll ones = (ones_cache[k] == -1) ? count1(n - p, k) : ones_cache[k];
        ones_cache[k] = ones;
        ll count0 = totalCount - ones;
        ll onesAll = count1(n, k);
        ans = (ans + count0 + onesAll) % MOD;
    }
    return ans % MOD;
}

signed main() {
    // for (int i = 0; i < 10000; i++) {
    //     if (o(i) != b(i)) {
    //         cout << "H: " << i << o(i) << ' ' << b(i) << '\n';
    //         return 0;
    //     }
    //     cout << i << ' ';
    // }
    // cout << "All Passed!";
    // cout << "HERE";
    cout << b(1000000);
    return 0;
}
