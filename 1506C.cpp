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
    string a, b, c; cin >> a >> b;
    if (a.size() > b.size())
        swap(a, b);
    int n = a.size(), mx = 0, m = b.size();
    // for (int len = n; len > -1; len--){
    //     for (int i = 0; i+len<=n; i++){
    //         c = a.substr(i, len);
    //         if (b.find(c) != string::npos){
    //             print(c);
    //             kill(- c.size() * 2 + a.size() + b.size());
    //         }
    //     }
    // }
    for (int len = a.size(); len > -1; len--){
        for (int i = 0; i+len <= n; i++){
            string c = a.substr(i, len);
            if (b.find(c) != string::npos)
                kill(a.size() + b.size() - 2 * c.size());
        }
    }
    //________________________
    return 0;
}