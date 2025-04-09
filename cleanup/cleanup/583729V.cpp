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
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n, x, cnt = 0; cin >> n >> x;
    int pfx[n+1]{};
    for (int i = 1; i<=n; i++){
        int t; cin >> t;
        pfx[i] += t + pfx[i-1];
    }
    // each(i, pfx)
    //     cout << i << ' ';
    for (int i = 0; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (pfx[j] - pfx[i] == x)
                cnt++;
        }
    }
    cout << cnt;
}