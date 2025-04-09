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
int N = 1e6;
unordered_set<int> uste;
void precompute(){
    int x = 2020, y = 2021;
    for (int i = 0; i*x <= N; i++){
        for  (int j = 0; i*x + j*y <= N; j++){
            uste.insert(i*x + j*y);
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // precompute();
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
void solve(){
    int n;cin >> n;
    // cout << (uste.count(n) ? "YES" : "NO");
    int c21 = n%2020;
    int c20 = (n-c21)/2020 - c21;
    if (c20 > -1 && (c21 * 2021 + c20 * 2020 == n))
        kill("YES");
    kill("NO");
}