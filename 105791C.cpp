#define ONLINE_JUDGE
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
const int MOD = 1e9 + 7; // Example prime modulus

// Function to compute maximum subarray product mod M
ll maxSubarrayProduct(vector<ll>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    ll maxProd = nums[0], minProd = nums[0], result = nums[0];
    
    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) swap(maxProd, minProd);
        
        maxProd = (nums[i] * maxProd) % MOD;
        minProd = (nums[i] * minProd) % MOD;
        
        maxProd = max((ll)nums[i], maxProd);
        minProd = min((ll)nums[i], minProd);
        
        result = max(result, maxProd);
        
        // Handling negative values properly to avoid negative mod results
        if (maxProd < 0) maxProd += MOD;
        if (minProd < 0) minProd += MOD;
    }
    
    return result;
}

void solve() {
    ll n; cin >> n;
    vector<ll> v(n);
    each(i, v)
        cin >> i;
    cout << max(1ll, maxSubarrayProduct(v));
}