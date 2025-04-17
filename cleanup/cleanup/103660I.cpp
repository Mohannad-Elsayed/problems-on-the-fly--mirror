#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
void fileIO(){
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
}

#define int ll

const int MOD = (int)1e9 + 7;
int dx[] = {1, -1, 0, 0, };
int dy[] = {0, 0, 1, -1, };

// Function to compute the length (and optionally the sequence) 
// of the longest non-decreasing subsequence in O(n²)
int longestNonDecreasingSubsequence(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    
    // dp[i] will hold the length of the longest non-decreasing subsequence ending at index i.
    vector<int> dp(n, 1);
    
    // Variable to track the index where the longest subsequence ends.
    int maxLength = 1, lastIndex = 0;
    
    // Compute dp array
    for (int i = 1; i < n; i++) {
        if (arr[i] < 0)
            continue;
        for (int j = 0; j < i; j++) {
            // Check the non-decreasing condition: arr[j] <= arr[i]
            if (arr[j] <= arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        // Update overall maximum length and the corresponding ending index.
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }
    
    return maxLength-1;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n), dif(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        dif[i] = a[i] - b[i];
        if(i)
            dif[i] += dif[i - 1];
    }

    int ans = longestNonDecreasingSubsequence(dif);
    cout << (ans ? ans : -1) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // fileIO();
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
//        cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}