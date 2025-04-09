#pragma GCC optimize("O2,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
#define forr(i, st, end) for (size_t i = st; i < end; i++)
#define int long long
int __ceil (int m, int a) { return (m + a - 1) / a; }

vector<int> a(1e5);
map<int, int> mp;

inline void precomute () {
    iota(a.begin(), a.end(), 0);
    forr(i, 1, 1e5) {
        a[i] += a[i-1];
        mp[a[i]] = i;
    }
    mp[a[0]] = 0;
}


inline void solve() {
    int n; cin >> n;
    int l = 0, r = a.size() - 1;
    int m, ans = -1;

    while (l <= r) {
        m = (l + r) / 2;
        if (a[m] >= n) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    if (ans == -1) {
        cout << -1;
        return;
    }

    int ri = min(n - 1, (int) a.size() - 1);
    forr(i, ans, ri + 1) {
        if (i >= a.size()) {
            cout << -1;
            return;
        }
        if (mp.count(a[i] - n) and i < n) {
            cout << mp[a[i] - n] + 1 << ' ' << i;
            return;
        }
    }
    cout << -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int __t = 1;
    cin >> __t;
    precomute();
    while (__t--) {
        solve();
        cout << '\n';
    }
}