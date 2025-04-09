// #define ONLINE_JUDGE
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
    int n, m; cin >> n >> m;
    n *= m;
    vector<int> v(n);
    each(i, v)
        cin >> i;
    int neg = 0, pos = 0, z = 0, s = 0, mn = 10000;
    each(i, v){
        if (i < 0)
            neg++;
        if (i > 0)
            pos++;
        if (!i)
            z++;
        s += abs(i);
        mn = min(mn, abs(i));
    }
    if ((neg%2) == 0)
        kill(s);
    s -= 2 * mn;
    kill(s);
}