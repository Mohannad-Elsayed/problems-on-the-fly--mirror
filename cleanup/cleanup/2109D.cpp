#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> A(l);
    for (int i = 0; i < l; ++i) cin >> A[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> d(n + 1, -1);
    d[1] = 0;
    queue<int> q;
    q.push(1);
    bool bipartite = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            } else {
                if ((d[u] % 2) == (d[v] % 2)) {
                    bipartite = false;
                }
            }
        }
    }

    int sum_S = accumulate(A.begin(), A.end(), 0);
    int sum_parity = sum_S % 2;

    int c = INT_MAX;
    if (!bipartite) {
        for (int u = 1; u <= n; ++u) {
            for (int v : adj[u]) {
                if (v < u) continue; // process each edge once
                if ((d[u] % 2) == (d[v] % 2)) {
                    int candidate = d[u] + d[v] + 1;
                    if (candidate % 2 == 1) {
                        if (candidate < c) {
                            c = candidate;
                        }
                    }
                }
            }
        }
    }

    string ans;
    for (int i = 1; i <= n; ++i) {
        if (bipartite) {
            if (sum_parity == (d[i] % 2) && sum_S >= d[i] && (sum_S - d[i]) % 2 == 0) {
                ans += '1';
            } else {
                ans += '0';
            }
        } else {
            if (sum_parity == (d[i] % 2)) {
                if (sum_S >= d[i]) {
                    ans += '1';
                } else {
                    ans += '0';
                }
            } else {
                if (sum_S >= d[i] + c) {
                    ans += '1';
                } else {
                    ans += '0';
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}