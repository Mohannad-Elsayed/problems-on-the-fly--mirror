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
    int n; cin >> n; 
    vector<int> v(n);
    each(i, v)
        cin >> i;

    if (is_sorted(all(v)))
        kill("1 1");
    
    pair<int, int> ans {0, 0};
    ll change = 0, mnchange = 0, cntl, cntr;

    for (int i = 0; i < n; i++){
        cntl = 0, cntr = 0, change = 0;
        for (int j = i+1; j < n; j++){
            // if (v[i] > v[j]){
            //     cntl++;
            // }
            // else if (v[i] < v[j]){
            //     cntr++;
            // }
            // if ()

            if (v[i] > v[j])
                change -= 1;
            else if (v[i] < v[j])
                change += 1;
            // print(i, j, cntl, cntr, change);
            if (mnchange > change){
                mnchange = change;
                ans = make_pair(i, j);
            }
        }
    }

    print(mnchange, ans);
    cout << ans.first+1 << ' ' << ans.second+1;
    
}