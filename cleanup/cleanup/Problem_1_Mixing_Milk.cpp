#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
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
    // cin >> tt;
    freopen("mixmilk.in", "rt", stdin);
    freopen("mixmilk.out", "wt", stdout);
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
struct bucket {
    int cap, am;
};
void solve(){
    vector<bucket> buckets(3);
    each(i, buckets)
        cin >> i.cap >> i.am;
    
    for (int i = 0; i<100; i++){
        int from = i%3, to = (i+1)%3;
        int am = min(buckets[to].cap - buckets[to].am, buckets[from].am);
        buckets[to].am += am;
        buckets[from].am -= am;
    }
    each(i, buckets)
        cout << i.am << '\n';
}