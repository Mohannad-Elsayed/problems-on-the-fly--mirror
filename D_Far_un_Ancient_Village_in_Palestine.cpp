#include "bits/stdc++.h"
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
#else
    #define print(...)
    #define printarr(...)
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
    int n, k, t; 
    cin >> n >> k;
    map<int, int> p_factors;
    while(n--){
        cin >> t;
        for (int i = 2; i*i <= t; i++){
            while(t%i == 0)
                p_factors[i]++, t /= i;
        }
        if (t != 1)
            p_factors[t]++;
    }

    for (auto [x, y] : p_factors){
        if (y % k != 0){
            cout << "NO"; 
            return 0;
        }
    }
    cout << "YES";
    //________________________
    return 0;
}