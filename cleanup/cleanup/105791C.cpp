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
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<31);
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll

ll fp(ll b, ll n, ll MOD = 1ll<<62) {
    b %= MOD;
    ll s = 1;
    while (n) {
        if (n & 1) s = s * b % MOD;
        b = b * b % MOD;
        n /= 2;
    }
    return s;
}


int maxEvenNegativeSubarraySum(const vector<int>& nums) {
    // dp[i][j] = max subarray sum ending at position i with j%2 negative numbers
    vector<vector<int>> dp(2, vector<int>(2, INT_MIN));
    int result = INT_MIN;
    
    for (int num : nums) {
        // Skip zeros as required
        if (num == 0) continue;
        
        // Create a new state without affecting the current one
        vector<vector<int>> new_dp(2, vector<int>(2, INT_MIN));
        
        // Is the current number negative?
        bool is_neg = (num < 0);
        
        // Start a new subarray with the current element
        new_dp[0][is_neg] = num;
        
        // Extend existing subarrays
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (dp[i][j] != INT_MIN) {
                    // Decide whether to include this number in previous subarray
                    int new_j = (j + is_neg) % 2;
                    new_dp[1][new_j] = max(new_dp[1][new_j], dp[i][j] + num);
                }
            }
        }
        
        // Update result for even number of negatives
        if (new_dp[0][0] != INT_MIN) result = max(result, new_dp[0][0]);
        if (new_dp[1][0] != INT_MIN) result = max(result, new_dp[1][0]);
        
        dp = new_dp;
    }
    
    return (result == INT_MIN) ? 0 : result;
}

void solve() {
    int n; cin >> n;
    vector<int> nums(n), lgs(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
        if (nums[i]) {
            lgs[i] = __lg(abs(nums[i]));
            if (nums[i] < 0)
                lgs[i] *= -1;
        }
    }
    print(nums);
    print(lgs);
}