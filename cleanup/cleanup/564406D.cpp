#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int LOG = 20;
int st[MAXN][LOG];
int log2Table[MAXN];

// Precompute log values
void computeLog(int n) {
    log2Table[1] = 0;
    for (int i = 2; i <= n; i++)
        log2Table[i] = log2Table[i/2] + 1;
}

// Build sparse table for GCD
void buildSparseTable(vector<int>& A, int n) {
    for (int i = 0; i < n; ++i)
        st[i][0] = A[i];

    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 0; i + (1 << j) <= n; ++i)
            st[i][j] = __gcd(st[i][j-1], st[i + (1 << (j-1))][j-1]);
}

// Query GCD from l to r
int queryGCD(int l, int r) {
    int j = log2Table[r - l + 1];
    return __gcd(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    computeLog(MAXN);

    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];

        buildSparseTable(A, n);

        int q;
        cin >> q;
        while (q--) {
            int len;
            cin >> len;
            int maxGCD = 0;

            for (int i = 0; i + len - 1 < n; ++i) {
                int currGCD = queryGCD(i, i + len - 1);
                maxGCD = max(maxGCD, currGCD);
            }
            cout << maxGCD << "\n";
        }
    }

    return 0;
}
