// #define ONLINE_JUDGE
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
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
using ll = long long;
template <typename T>
ll count_below(vector<T>& v, int sz, ll Limit){
    ll total = 0;
    for (int i = 0, j = sz-1; i < j; i++){
        print(i, j, v[i]+v[j], j-i);
        while(j > i && v[i] + v[j] > Limit)
            j--;
        print(i, j, v[i]+v[j], j-i);
        total += max(0, j-i);
    }
    return total;
}
void solve(){
    int n, L, R;
    ll ans = 0; 
    cin >> n >> L >> R;
    vector<int> v(n);
    each(i, v)
        cin >> i;
    sort(all(v));

    kill(count_below(v, n, R) - count_below(v, n, L-1));
}