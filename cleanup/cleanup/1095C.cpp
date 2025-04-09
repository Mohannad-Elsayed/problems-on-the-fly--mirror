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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    ll n, k; cin >> n >> k;
    if (__builtin_popcountll(n) > k)
        kill("NO");
    if (__builtin_popcountll(n) == k){
        cout << "YES\n";
        for (int i = 0; i< 31; i++){
            if ((n >> i) & 1)
                cout << (1 << i) << ' ';
        }
        return;
    }
    multiset<int, greater<>> powers;
    for (int i = 0; i< 31; i++){
        if ((n >> i) & 1)
            powers.insert(1 << i);
    }
    // print(powers);
    while (*powers.begin() != 1 && powers.size() < k) {
        int p = *powers.begin();
        powers.erase(powers.begin());
        p /= 2;
        powers.insert(p);
        powers.insert(p);
    }
    if (powers.size() == k){
        cout << "YES\n";
        each(i, powers)
            cout << i << ' ';
    }
    else kill("NO");
}