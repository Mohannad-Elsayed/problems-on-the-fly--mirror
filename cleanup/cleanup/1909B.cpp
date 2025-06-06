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
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n; cin >> n;
    vector<ll> v(n);
    each(i, v) cin >> i;
    ll mod, i;
    for (mod = 2, i = 1; i < 62; i++, mod <<= 1) { // change to << 1
        set<ll> ste;
        each(i, v) ste.insert(i%mod);
        vector<ll> mds(n);
        for (int i = 0; i<n; i++)
            mds[i] = v[i]%mod;
        if (ste.size() == 2) {
            print(mds);
            kill(mod);
        }
    }
    print(mod);
}