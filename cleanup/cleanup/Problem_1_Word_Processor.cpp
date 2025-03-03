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
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n, k; 
    cin >> n >> k;
    vector<string> v(n);
    each(i, v)
        cin >> i;
    
    cout << v.front();
    int current = v.front().size();
    for (int i = 1; i < n; i++){
        if (current + v[i].size() > k)
            current = 0;
        cout << (current ? ' ' : '\n');
        cout << v[i];
        current += v[i].size();
    }
}