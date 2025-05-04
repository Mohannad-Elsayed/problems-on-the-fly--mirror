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
vector<int> ans(1);
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    ans.push_back(1);
    for (int i = 1, j = 1; i <= 1000; i++, j++) {
        ans.push_back(ans.back()+j);
        ans.push_back(ans.back()+j);
    }
    for (int i = 1; i <= 40; i++)
        cout << i << ' ' << ans[i] << '\n';
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
void stress(){
    int n = 8;
    vector<int> v(n);
    iota(all(v), 1);
    set<int> ste;
    do {
        int sum = 0;
        for (int i = 1; i <= n; i++) 
            sum += abs(v[i-1]-i);
        ste.insert(sum);
    } while(next_permutation(all(v)));
    print(ste);
    print(ste.size());
    exit(0);
}
void solve() {
    // stress();
    int n; cin >> n; 
    cout << ans[n];
}