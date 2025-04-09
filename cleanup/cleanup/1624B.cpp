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

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll g1 = 2*b - c, // new A
    g2 = 2*b - a, // new C
    g3 = a+c; // new B
    if (g1 > 0 && g1 % a == 0)
        kill("YES");
    if (g2 > 0 && g2 % c == 0)
        kill("YES");
    if (g3 > 0 && ((g3%2 == 0) && ((g3/2)%b == 0)))
        kill("YES");
    cout << "NO";
}