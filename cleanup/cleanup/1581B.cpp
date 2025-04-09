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
    ll n, m, k; 
    cin >> n >> m >> k;
    ll mx = (n * (n-1))/2;
    if (m < n-1 || m > mx)
        kill("NO");
    ll d = -1;
    if (!m)
        d = 0;
    else if (m == mx)
        d = 1;
    else
        d = 2;
    k--;

    assert(d != -1);

    if (m <= mx && d < k)
        kill("YES");
    kill("NO");
}