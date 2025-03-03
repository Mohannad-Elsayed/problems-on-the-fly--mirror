#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
    #pragma GCC optimize("O3,unroll-loops,Ofast")
    // #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    pre(); 
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
    vector<ll> a(n), b(n), as, bs;
    each(i, a) cin >> i;
    each(i, b) cin >> i;

    function<ll(ll m)> can = [&](ll m) -> ll {
        ll negs = k, prof = 0;
        for (int i = 0; i<n; i++){
            if (m > b[i])
                continue;
            else if (m > a[i]){
                prof += min(m, b[i]);
                if (!negs)
                    return 0ll;
                negs--;
            }
            else    
                prof += min(m, a[i]);
        }
        return prof;
    };

    as = a, bs = b;
    sort(all(as));
    sort(all(bs));


    ll mxp = -inf<ll>;
    for (int i = 0; i<n; i++){
        ll currp = as[i], people = n;
        ll l = 0, r = n-1, m, res = -1;
        while(l<=r){
            m = (l+r)/2;
            if (bs[m] < currp){
                res = m;
                l = m+1;
            } else r = m-1;
        }
        people -= res+1;
        print(people, currp, res, i);
        ll negr = i-(res+1);
        print(negr);
        if (negr <= k)
            mxp = max(mxp, people * currp);
    }

    for (int i = 0; i<n; i++){
        ll currp = bs[i], people = n;
        ll l = 0, r = n-1, m, res = -1;
        while(l<=r){
            m = (l+r)/2;
            if (as[m] < currp){
                res = m;
                l = m+1;
            } else r = m-1;
        }
        print(people, currp, res, i);
        ll negr = i-(res+1);
        print(negr);
        if (negr <= k)
            mxp = max(mxp, people * currp);
    }


    cout << mxp;
    //________________________
    return 0;
}