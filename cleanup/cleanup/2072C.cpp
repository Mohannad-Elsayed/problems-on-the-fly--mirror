// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
void solve();
int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    ll n, x;
    cin >> n >> x;
    if (n == 1)
        kill(x);
    
    vector<ll> ans;
    int i, tx = x;
    for (i = 0; (int)ans.size()+1 < n; i++)
        if ((x|i) == x){
            ans.push_back(i);
            for (int bit = 0; bit < 30; bit++){
                ll valp = (1ll << bit);
                if (i&valp && tx&valp){
                    tx ^= valp;
                    // print(tx, valp);
                }
            }
        }
        else
            break;

    
    print(ans, i, tx, x, x|i, !tx && ((x|i) == x));
    ans.push_back((!tx && ((x|i) == x)) ? i : tx);
    // // ans.push_back(tx ? tx : i);
    while (ans.size() < n)
        ans.push_back(tx);
    each(i, ans)
        cout << i << ' ';


}