#include "bits/stdc++.h"
#pragma GCC optimize("O3")
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
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("out.out", "wt", stdout);
    // freopen("out.out", "wt", stderr);
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
    ll n, k; cin >> n >> k;
    vector<ll> divs;
    // divs.reserve(n);
    ll sq = sqrtl(n);
    for (ll i = 1; i <= sq; i++){
        if (n % i == 0){
            divs.emplace_back(i);
            if (n / i != i)
                divs.emplace_back(n/i);
        }
        
    }
    sort(all(divs));
    print(divs);
    if (k > divs.size())
        kill(-1);
    cout << divs[--k];
    //________________________
    return 0;
}