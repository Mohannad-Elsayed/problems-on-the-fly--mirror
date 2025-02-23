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
    // cin >> tt;
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
    vector<int> v(n);
    each(i, v)
        cin >> i;
    
    vector<map<int, int>> vmp;
    vector<int> twos, threes;
    each(ele, v){
        int ti = ele, cnttw = 0, cntth = 0;
        while(ti%2==0)
            ti /= 2, cnttw++;
        while(ti%3==0)
            ti /= 3, cntth++;
        map<int, int> mp;
        for (ll i = 2; i*i <= ti; i++){
            while(ti%i==0)
                ti /= i, mp[i]++;
        }
        if (ti != 1)
            mp[ti]++;
        vmp.push_back(mp);
        twos.push_back(cnttw);
        threes.push_back(cntth);
    }
    sort(all(vmp));
    print(vmp);
    if (vmp.back() != vmp.front())
        kill(-1);
    sort(all(twos));
    sort(all(threes));
    print(twos);
    print(threes);
    cout << accumulate(all(twos), 0ll) + 
            accumulate(all(threes), 0ll) - 
            n * (twos.front() + threes.front());
    //________________________
    return 0;
}