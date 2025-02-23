#include <bits/stdc++.h>
using namespace std;

// change N to worst case
// Total complexity O(function in merge)

namespace sparsetable {
    using ll = long long;
    constexpr int N = 2e5 + 5, LOGsz = ceil(log((long double)N));
    ll n, q, s[N], T[N][LOGsz], Log[N];
    ll merge(ll a, ll b) { //* change operation
        // max, min, gcd, lcm, bitwise operations,
        return gcd(a, b);
    }
    void build() {
        for (int i = 0; i < n; i++) {
            T[i][0] = s[i];
        }
        for (int pw = 1; (1 << pw) <= n; pw++) {
            for (int i = 0; i + (1 << pw) <= n; i++) {
                T[i][pw] = merge(T[i][pw - 1], T[i + (1 << (pw - 1))][pw - 1]);
            }
        }
    }
    ll query(int l, int r) { // one based, effective
        int sz = r - l + 1;
        int pw = Log[sz];
        return merge(T[l][pw], T[r - (1 << pw) + 1][pw]);
    }
    ll query2(int l, int r) { // one based
        if (r < l) return LLONG_MAX;
        int sz = r - l + 1;
        ll ret = LLONG_MAX;
        for (int i = 0; i < 22; i++)
            if ((sz >> i) & 1) return merge(query(l + (1 << i), r), T[l][i]);
        return ret;
    }
    void preCount() {
        Log[1] = 0;
        for (int i = 2; i < N; i++) Log[i] = Log[i >> 1] + 1;
    }
}
