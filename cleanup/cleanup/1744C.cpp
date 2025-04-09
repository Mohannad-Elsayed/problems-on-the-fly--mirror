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
    int n, t, ans = -1, f = -1; char k; string s;
    cin >> n >> k >> s;
    s += s;
    print(n, k, s);
    n = s.size();
    for (int i = 0; i<n/2; i++){
        if (i > f)
            for (int j = i; j < n; j++)
                if (s[j] == 'g'){
                    f = j;
                    break;
                }
        if (s[i] == k)
            ans = max(ans, f - i);
    }
    cout << ans;
    //________________________
    return 0;
}