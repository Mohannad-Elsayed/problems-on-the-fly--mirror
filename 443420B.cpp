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
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
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
    ll n, k; 
    cin >> n >> k;
    ll row = (n+k-1)/k;
    if (row%2)
        kill("YES");
    
    if (k%2 == 0){
        print(n, k);
        kill("NO");
    }

    ll val1 = row * k;
    ll val2 = val1 - k + 1;
    print(val1, val2);
    if (n == (val1+val2)/2)
        kill("YES");
    print(n, k);
    kill("NO");
}