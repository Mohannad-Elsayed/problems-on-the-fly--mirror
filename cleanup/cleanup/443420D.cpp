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
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    freopen("game.in", "rt", stdin);
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n; cin >> n;
    vector<ll> v(n), pfx(n), sfx(n);
    each(i, v)
        cin >> i;
    pfx[0] = v[0];
    for (int i = 1; i < n; i++)
        pfx[i] += pfx[i-1] + v[i];
    sfx[n-1] = v[n-1];
    for (int i = n-2; ~i; i--)
        sfx[i] += sfx[i+1] + v[i];
    print(pfx);
    print(sfx);
    ll comp = -1, saeed;
    for (int i = 0; i<n; i++)
        chmax(comp, min(pfx[i], sfx[i]));
    saeed = pfx.back() - comp;
    cout << (comp > saeed ? "Compiler" : (comp < saeed ? "Saeed" : "Tie"));
}