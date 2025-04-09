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
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        // i/
    }return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    each(i, v)
        cin >> i;
    
    string s = "abcdefghijklmnopqrstuvwxyz";
    s += s;
    
    vector<string> ans(n+1, s);
    for (int i = 0; i<n; i++){
        // lsp between ans[i] and ans[i+1] = v[i]
        for (int k = 0; k < v[i]; k++)
            ans[i+1][k] = ans[i][k];
        ans[i+1][v[i]] = ans[i][v[i]] + 1;
        ans[i+1][v[i]] = ((ans[i+1][v[i]]-'a') + 26) % 26 + 'a';
    }
    each(i, ans)
        cout << i << '\n';
} 