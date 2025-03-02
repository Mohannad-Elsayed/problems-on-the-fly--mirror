#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "../debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n, ans = 1e7; string s; 
    cin >> n >> s;
    for (int i = 0; i<n; i++){
        for (int j = i+1; j < n; j++){
            string ss;
            for (int k = i; k <= j; k++)
                ss.push_back(s[k]);
            int ca = count(all(ss), 'a');
            int cb = count(all(ss), 'b');
            int cc = count(all(ss), 'c');
            if (ca > cb && ca > cc){
                print(ss, ans, j-i+1);
                ans = min(ans, j-i+1);
            }
        }
    }
    cout << (ans > 1e6 ? -1 : ans);
}