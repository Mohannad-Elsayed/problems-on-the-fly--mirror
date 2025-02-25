#include "bits/stdc++.h"
using namespace std;
#define ll long long
void TC() {
    ll n; cin >> n;
    vector<vector<int>> vec(n);
    vector<ll> sumAll(n) ,  sz(n);
    for (int i = 0; i < n; i++) {
        ll m; cin >> m;
        sz[i] = m;
        vec[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            sumAll[i] += vec[i][j];
        }
    }
    ll queryAll;
    cin >> queryAll;
    while(queryAll--) {
        ll q; cin >> q;
        ll ans = 0 ,  mn = LLONG_MAX , tot;
        for (int j = 0; j < n; j++) {
            tot = 0;
            for (int k = 0; k < sz[j]; k++)
                tot += abs(vec[j][k] - q);
            if (tot < mn)
                mn = tot , ans = j + 1;
        }
        cout << ans << " ";
    }
    cout << '\n';
}

int32_t main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long tc = 1;
//    cin >> tc;
    for (int test = 1; test <= tc; ++test) {
        TC();
    }
//    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
    return 0;
}