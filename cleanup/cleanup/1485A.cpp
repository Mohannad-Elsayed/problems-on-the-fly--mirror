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
    // freopen("in.in", "rt", stdin);
    pre();
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    int a = 1000, b = 2;
    cout << a/(b+1) << ' ' << a/(b+1)/(b+1);
    exit(0);

    //________________________
    return 0;
}

bool f = false;
int rec(int a, int b){
    if (f)
        return 0;
    if (b > a)
        return 1;
    if (!a){
        f = true;
        return 0;
    }
    return 1 + min(rec(a/b, b), rec(a, b+1));
}

int solve(){
    int a, b, cnt = 0, ans = inf<int>, ta, tb; 
    cin >> a >> b;
    ta = a;
    tb = b;
    if (a < b)
        kill(1);

    if (a == b)
        kill(2);
    
    for (int i = 0; i < 40; i++){
        a = ta;

        b = tb + i;
        if (b == 1){
            continue;
        }
        cnt = i;
        while(a >= b){
            a /= b;
            cnt++;
        }
        ans = min(ans, cnt);
        print(i, a, b, cnt);
    }
    
    cout << ans+1;
    //________________________
    return 0;
}