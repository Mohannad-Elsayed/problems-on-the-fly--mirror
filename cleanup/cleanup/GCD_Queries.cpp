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
    cout << 5%1;

    //________________________
    return 0;
}
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
    ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
    ll sub(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }
ll MOD = 1'000'000'007ll;
int solve(){
    ll n, q, t, gg = -1, ans; cin >> n >> q;

    while(n--){
        cin >> t;
        if (gg == -1)
            gg = t;
        else
            gg = gcd(gg, t);
    }
    print(t);
    while(q--){
        cin >> t;
        gg = ((t * gg)%(MOD) + MOD) % MOD;
        cout << gg << '\n';
    }
    
    //________________________
    return 0;
}