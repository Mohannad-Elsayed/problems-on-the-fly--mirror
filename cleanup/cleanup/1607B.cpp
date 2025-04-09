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
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
void stress() {
    int curr = 11;
    for (int i = 0; i<10; i++) {
        if (curr&1)
            curr += i;
        else    
            curr -= i;
        cout << i << ' ' << curr << '\n';
    }
}
#define int ll
void solve() {
    // stress();
    int x, n; cin >> x >> n;
    int arre[] = {0, -n, 1, n+1}, 
        arro[] = {0, n, -1, -n-1};
    int ans;
    if (x&1) 
        ans = x + arro[n%4];
    else
        ans = x + arre[n%4];
    cout << ans;
}