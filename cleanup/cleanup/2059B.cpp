#include <bits/stdc++.h>
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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    each(i, v)
        cin >> i;
    
    if (n == 2){
        if (v.back() == 1)
            kill(2);
        kill(1);
    }
    
    if (count(all(v), 1) == n)
        kill(2);

    int curr = 1;
    if (n == k){
        for (int i = 1; i<n; i+=2){
            if (curr != v[i])
                break;
            curr++;
        }
        kill(curr);
    }

    if (k == 2 || v[1] != 1)
        kill(1);

    int g = n-k+1;
    print(g);
    
    if (g == 2){
        if (v[1] == v[2] && v[2] == 1)
            kill(2);
        kill(1);
    }

    print(count(v.begin(), v.begin()+g, 1));

    if (count(v.begin(), v.begin()+g, 1) == g && v[g] == 1)
        kill(2);
    kill(1);


    //________________________
    return 0;
}