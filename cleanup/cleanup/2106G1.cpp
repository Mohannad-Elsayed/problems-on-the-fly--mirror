#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> tree(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // Get the total sum of f(i) for all nodes
        cout << "? 1 " << n;
        for (int i = 1; i <= n; ++i) {
            cout << " " << i;
        }
        cout << endl;
        cout.flush();

        int total_sum;
        cin >> total_sum;

        vector<int> values(n + 1);
        for (int i = 1; i <= n; ++i) {
            // Toggle node i
            cout << "? 2 " << i << endl;
            cout.flush();

            // Query total sum again
            cout << "? 1 " << n;
            for (int j = 1; j <= n; ++j) {
                cout << " " << j;
            }
            cout << endl;
            cout.flush();

            int new_total_sum;
            cin >> new_total_sum;

            int diff = new_total_sum - total_sum;
            // Since f(i) changes by ±depth(i)*2, and depth = 1 for all except the root
            // Try assuming node i is root
            int val = diff;  // if root, f(i) changes by 2*val (rest stay the same)
            if (val % 2 == 0 && abs(val) <= 2 * n) {
                values[i] = -val / 2;
            } else {
                // Otherwise, value is changed in all f(i) where path includes i => depth = 1
                // So value contributes to all nodes (except root)
                values[i] = -diff / (2 * (n - 1));
            }

            // Toggle back to restore original value
            cout << "? 2 " << i << endl;
            cout.flush();
        }

        // Output the final result
        cout << "!";
        for (int i = 1; i <= n; ++i) {
            cout << " " << values[i];
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}
