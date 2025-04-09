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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i<n; i++)
        cin >> a[i] >> b[i];
    
    int mxa = a[0], mxb = b[0];
    for (int i = 0; i<n; i++) {
        chmin(mxa, a[i]);
        chmax(mxb, b[i]);
    }
    for (int i = 0; i<n; i++) { 
        if (a[i] == mxa && b[i] == mxb)
            kill(i+1);
    }
    cout << -1;
}


For each test case, output two integers:
- The number of subsequences with XOR equal to 0.
- The number of subsequences with XOR equal to 1.

