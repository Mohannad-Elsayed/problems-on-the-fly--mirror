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
    int n, k; 
    cin >> n >> k;
    vector<int> p_fac;
    for (int i = 2; i*i <= n; i++){
        while(n % i == 0)
            n /= i, p_fac.emplace_back(i);
    }
    if (n != 1)
        p_fac.emplace_back(n);
    print(p_fac);
    if (p_fac.size() < k)
        kill(-1);
    
    for (int i = 0; i+1 < k; i++)
        cout << p_fac[i] << ' ';
    
    int last = 1;
    for (int i = k-1; i < p_fac.size(); i++)
        last *= p_fac[i];
    cout << last;
    //________________________
    return 0;
}