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
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    string win = "Ashishgup", lose = "FastestFinger";
    int n; cin >> n;
    if (__builtin_popcount(n) == 1 && n != 2)
        kill(lose);

    int twos = 0;
    while(n > 1 && n %2 == 0) 
        n /= 2, twos++;

    int odds = 0;
    for (int i = 3; i*i <= n; i+=2)
        while(n%i == 0)
            n/=i, odds++;
    if (n != 1)
        odds++;
    
    // print(odds, twos);
    if (odds == 1 && twos == 1)
        kill(lose);
    kill(win);
}