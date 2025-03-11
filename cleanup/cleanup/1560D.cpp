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
void solve();
vector<string> powers;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    for (ll i = 1, p = 0; p < 54; p++, i *= 2)
        powers.push_back(to_string(i));
    // print(powers);
    // exit(0);
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int lcs(string a, string base){
    int i = 0, j = 0;
    for (; i < a.size(); i++)
        if (a[i] == base[j])
            j++;
    return j;
}
void solve() {
    string s, ss; cin >> s;
    int n = s.size();
    int ans = 1e9;
    each(p2, powers){
        // print(s, p2, lcs(s,p2));
        chmin(ans, int(n+p2.size()-2*lcs(s, p2)));
    }
    cout << ans;
}