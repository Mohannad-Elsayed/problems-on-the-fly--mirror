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

void solve() {
    int n; cin >> n;
    n *= 2;
    vector<pair<int, int>> odds, evens;
    for (int i = 1; i<=n; i++) {
        int t; cin >> t;
        if (t&1)
            odds.emplace_back(t, i);
        else
            evens.emplace_back(t, i);
    }
    print(odds);
    print(evens);
    int cnt = n/2-1;
    while(cnt--) {
        if (evens.size() > 2) {
            cout << evens.back().second;
            evens.pop_back();
            cout << ' ' << evens.back().second << '\n';
            evens.pop_back();
            continue;
        }
        cout << odds.back().second;
        odds.pop_back();
        cout << ' ' << odds.back().second << '\n';
        odds.pop_back();
    }
}