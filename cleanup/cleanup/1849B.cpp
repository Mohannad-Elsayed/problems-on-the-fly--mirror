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
    cin >> tt;
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
    set<pair<int, int>, greater<>> mons;
    int n, k, t; cin >> n >> k;
    for (int i = 1; i<=n; i++){
        cin >> t;
        mons.insert(make_pair(t%k ? t%k : k, -i));
    }

    print(mons);
    while (mons.size()){
        pair<int, int> p = *mons.begin();
        mons.erase(mons.begin());   
        cout << p.second * -1 << ' ';
    }

    //________________________
    return 0;
}