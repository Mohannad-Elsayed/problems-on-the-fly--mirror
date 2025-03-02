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
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n; string s; 
    cin >> n >> s;
    each(ch, s)
        ch -= 'a';
    
    int mn = 1e6+1, f = 0;
    for (int i = 0; i<n; i++){
        int a[3]{};
        a[s[i]]++;
        for (int j = i+1; j < min(n, i+8); j++){
            a[s[j]]++;
            if (a[0] > a[1] && a[0] > a[2]){
                f = 1, mn = min(mn, j-i+1);
                print(i, j, mn, a[0], a[1], a[2]);
            }
        }
    }
    

    kill(f ? mn : -1);
}