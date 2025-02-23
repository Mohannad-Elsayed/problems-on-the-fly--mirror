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
#define ONLINE_JUDGE
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
    pre(); 
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    cout << "sdlkf";
    //________________________
    return 0;
}
int solve(){
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    each(i, v)
        cin >> i, mp[i]++;
    
    // int mpsz = int(mp.size());
    // if (mpsz == 1 || (mpsz == 2 && (n/2)%2==0))
    //     kill("Yes");
        
    // if (mp.begin()->second < 2)
    //     kill("No");
    
    // int f = mp.begin()->first, l = f;
    // for (auto [x, y] : mp)
    //     if (y%2)
    //         l = x;

    // print(v, mp, f, l);
    for (int i = 0; i <= 1000; i++){
        print(i, mp[i]);
        if (mp[i] == 1)
            kill("No");
        if (mp[i] > 1){
            mp[i+1] += mp[i] - 2;
            mp[i] = 2;
        }
    }
    
    kill("Yes");
    //________________________
    return 0;
}