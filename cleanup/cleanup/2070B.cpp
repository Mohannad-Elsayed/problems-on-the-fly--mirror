#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
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
    ll n, x, k;
    string commands;
    cin >> n >> x >> k >> commands;
    ll b = 0, ansb = -1, cnt = 0;
    
    cnt = 0;
    each(i, commands){
        b += (i == 'L' ? -1 : 1);
        cnt++;
        if (!b){
            ansb = cnt;
            break;
        }
    }

    ll a = x, ansa = -1;
    cnt = 0;
    each(i, commands){
        a += (i == 'L' ? -1 : 1);
        cnt++;
        if (!a){
            ansa = cnt;
            break;
        }
    }
    print(k, k-ansb);
    print(ansa, ansb);
    if (ansa == -1)
        kill(0);
    if (ansb == -1)
        kill(1);
    
    bool f = (k-ansa) > -1;
    cout << f + (f * (k-ansa))/ansb;
}