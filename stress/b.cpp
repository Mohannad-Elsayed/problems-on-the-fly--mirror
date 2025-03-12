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
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
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
template<typename T>
using mxpq =  priority_queue<T>;
template<typename T>
using mnpq =  priority_queue<T, vector<T>, greater<T>>;
void solve() {
    int n; cin >> n;
    mnpq<int> mste;
    for (int i = 0; i<n; i++){
        int t; cin >> t;
        mste.push(t);
    }
    // print(mste);
    while(mste.size() > 1) {
        int a = mste.top();
        mste.pop();
        int b = mste.top();
        mste.pop();
        mste.push(a+b-1);
    }
    cout << mste.top();
}