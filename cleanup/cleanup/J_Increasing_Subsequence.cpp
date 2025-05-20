// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
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
int rnglr(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("area.in", "r", stdin);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
template<class T>
int lis_size(T& nums) {
    vector<int> tail;
    for (auto x : nums) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    return tail.size();
}

vector<int> get_lis(vector<int>& nums) {
    int n = nums.size();
    vector<int> tail, idx, prev(n, -1), pos;

    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        auto it = lower_bound(tail.begin(), tail.end(), x);
        int j = it - tail.begin();

        if (it == tail.end()) {
            tail.push_back(x);
            idx.push_back(i);
        } else {
            *it = x;
            idx[j] = i;
        }

        if (j > 0)
            prev[i] = idx[j - 1];
    }

    vector<int> lis;
    for (int i = idx.back(); i >= 0; i = prev[i])
        lis.push_back(nums[i]);
    reverse(lis.begin(), lis.end());

    return lis;
}


void solve() {
    int n; cin >> n;
    vector<int> v(n), dp;
    getv(v);
    cout << lis_size(v);
}