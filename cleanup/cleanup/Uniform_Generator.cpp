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
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n, m, g;
    while (cin >> n >> m){
        g = __gcd(n, m) - 1;
        if (g){
            cout << setw(10) << n << 
                setw(10) << m << "    Bad Choice\n\n";
        }
        else {
            cout << setw(10) << n << 
                setw(10) << m << "    Good Choice\n\n";
        }
    }
}