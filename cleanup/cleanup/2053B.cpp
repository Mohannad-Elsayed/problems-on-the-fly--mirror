#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    map<int, int> mp;
    each(i, v){
        cin >> i.first >> i.second;
        if (i.first == i.second) 
            mp[i.first]++;
    }
    if (mp.empty())
        return cout << string(n, '1'), 0;
    string s(n, '0');
    for (int kk = 0; kk < n; kk++){
        pair<int, int> i = v[kk];
        print(mp.size(), (i.second-i.first+1), mp.count(i.first), mp.count(i.second), 
            mp.size() >= (i.second-i.first+1) && mp.count(i.first) && mp.count(i.second));
        // if (i.first==i.second&&mp.count(i.first)==1){
        //     s[kk]='1';continue;
        // }
        if (mp.size() >= (i.second-i.first+1) && mp.count(i.first) && mp.count(i.second)){
            for (int c = i.first; c<=i.second; c++)
                if (!mp.count(c)){
                    print(c);
                    s[kk] = '1';
                    break;
                }
        }
        else{
            print("here");
            s[kk] = '1';
        }
    }
    cout << s;
    //________________________
    return 0;
}