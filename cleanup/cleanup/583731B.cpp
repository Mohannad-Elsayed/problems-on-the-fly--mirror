#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << (x), 0;
#define killn(x) return cout << (x) << '\n', 0;

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}
int solve(){
    int n; cin >> n;
    ll arr[n];
    each(i, arr)
        cin >> i;
    int cnt = 0;
    for (int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            if (a == b)
                continue;
            for (int c = 0; c < n; c++){
                if (b == c || a == c)
                    continue;
                if (arr[a] * arr[b] * arr[b] - arr[a] * arr[a] * arr[b] == arr[c])
                    cnt++;
            }
        }
    }
    cout << (cnt ? to_string(cnt) : "Impossible");
    //________________________
    return 0;
}