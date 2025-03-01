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

void solve(){
    int n, cnt = 0; cin >> n;
    vector<int> v(n), freq(int(2e5+10)), pfx(n+1);
    each(i, v)
        cin >> i;
    
    for (int i = 1; i < n+1; i++){
        cnt += !freq[v[i] + int(1e5)];
        pfx[i] += cnt + pfx[i-1];
        freq[v[i] + int(1e5)]++;
    }
    
}