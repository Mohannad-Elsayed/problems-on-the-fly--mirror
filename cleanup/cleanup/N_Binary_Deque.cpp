#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define kill(x) return cout << (x), 0;
#define each(x, v) for (auto &(x) : (v))
#include "cleanup/debug.h"
int solve(){
    /*
    int n, k, t, s; cin >> n >> k;
    vector<int> v(n);
    each(i,v)
        cin >> i;;
    s = accumulate(all(v), 0);
    if (s < k)
        kill(-1);
    
    int cs = 0 // current sum
    , ans = -1;
    map<int, int> mp {{0, -1}}; // sum_idx
    for (int i = 0; i<n; i++){
        cs += v[i];
        if (mp.count(cs-k))
            ans = max(ans, i - mp[cs-k]);
        if (!mp.count(cs))
            mp[cs] = i;
    }
    cout << n-ans;
    */

    int n, k, s = 0, ans = 0; 
    cin >> n >> k;
    vector<int> v(n);
    each(i, v)
        cin >> i;
    if (k > accumulate(all(v), 0))
        kill(-1);
    for (int l = 0, r = 0; l < n; s-=v[l++]){
        while(r < n && s <= k)
            s += v[r++],
        print("wh", ans, l, r, s);
        if (s > k)
            ans = max(ans, r-l-1),
        print(ans, l, r, s);
    }
    cout << n-ans;
    //________________________
    return 0;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}