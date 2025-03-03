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
int N = 1e7+10;
vector<bool> v(N);
void pre(){
    for (int i = 0; i*i < N; i++)
        v[i*i] = 1;
}
bool isprfct(ll n){
    ll sq = sqrtl(n);
    while(sq*sq > n) sq--;
    while(sq*sq < n) sq++;
    return sq * sq == n;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    pre();
    // print(isprfct(249001000000));
    // print(isprfct(249001000000+998001));
    // exit(0);
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
void solve(){
    ll k, cnt = 0; cin >> k;
    for (int i = 0; i*i+k < N; i++){
        if (isprfct(i*i+k))
        // if (v[i*i+k])
            cnt++, print(i, i*i, i*i+k);
    }
    cout << cnt;
}