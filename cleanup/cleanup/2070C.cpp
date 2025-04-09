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
    // cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n, k; 
    string s;
    cin >> n >> k >> s;
    vector<int> penalty(n);
    each(i, penalty) cin >> i;
    // print(n, k, s);
    int cons_b{};
    int i = 0;
    while(i < n){
        if (s[i] == 'B'){
            cons_b++;
            while(i < n && s[i] == 'B') i++;
        }
        else i++;
    }
    // print(cons_b);
    if (cons_b <= k)
        kill(0);
    
    vector<int> bsp = penalty;
    sort(all(bsp));
    int l = 0, r = n-1, m, res = bsp.back();
    auto check = [&](int mid) -> bool {
        int currp = 0, maxp = -1;
        for (int i = 0; i<n; i++){
            if (s[i] == 'B' && ){
                
            }
        }
        return maxp <= mid;
    };
    while(l<=r){
        m = (l+r)>>1;
        if (check(m)){
            r = m-1;
            res = bsp[m];
        } else l = m+1;
    }
    cout << res;

}