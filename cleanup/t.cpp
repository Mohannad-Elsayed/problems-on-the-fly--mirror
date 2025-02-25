#include "bits/stdc++.h"
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif
using namespace std;
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
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n = 11;
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int e = 1, p = -1;
    for (int step = (1<<(__lg(n))); step; step /= 2)
        if (p+step < n && v[p+step] < e)
            p += step, print(p, step);
    cout << p;
}