#include <iostream>
#include <vector>
#include <algorithm>
#include "cleanup/debug.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt;
    ll sm = 0;
    vector<vector<int>> v(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] <= 0)
                cnt.push_back(-1 * v[i][j]);
            else
                sm += v[i][j];
        }
    }

    sort(cnt.rbegin(), cnt.rend());
    print(cnt);
    int k = cnt.size();
    for (int i = 0; i < k; i++) {
        sm += cnt[i];
    }

    if (k % 2) sm -= 2*cnt[k - 1];
    cout << sm << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();

    }
    return 0;
}
