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

void solve() {
    int n; 
    while(cin >> n, n) {
        vector<int> arr(n+1, 1e9), dp(n+1, 1), next(n+1), ans;
        for (int i = 1; i <= n; i++) 
            cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++)
                if (arr[j] < arr[i]) 
                    chmax(dp[i], dp[j]+1);
            for (int j = 1; j < i; j++) 
                if (arr[j] < arr[i] && dp[j]+1 == dp[i] && arr[j] < arr[next[i]])
                    next[i] = j;
                
            
        }
        print(dp);
        print(next);
        int mxdp = *max_element(all(dp));
        int mnel = 1e9; /*min element with max dp*/
        int mnelidx = -1; /*min element with max dp*/
        for (int i = 1; i <= n; i++)
            if (dp[i] == mxdp && arr[i] < mnel) {
                mnelidx = i;
                mnel = arr[i];
            }
        
        while(mnelidx) {
            ans.push_back(arr[mnelidx]);
            mnelidx = next[mnelidx];
        }
        reverse(all(ans));
        print(ans);
        cout << ans.size() << ' ';
        each(i, ans)
            cout << i << ' ';
        cout << '\n';
    }
}

/*
1  2 3     4 5  6  7   8
90 4 10000 2 18 60 172 99


*/