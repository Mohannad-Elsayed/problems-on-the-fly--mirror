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
    string s;
    ll n; cin >> n >> s;
    if (n < 3)
        kill(0);
    ll cnt1 = 0, // -
        cnt2 = 0;
    each(ch, s)
        if (ch == '-')
            cnt1++;
        else 
            cnt2++;
    print(cnt1, cnt2);
    cout << cnt1/2 * (cnt1/2+cnt1%2) * cnt2;
}