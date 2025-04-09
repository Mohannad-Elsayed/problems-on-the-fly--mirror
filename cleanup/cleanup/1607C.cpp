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
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    ll accu = 0;
    ll mx = -1E11;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int n; cin >> n;
    vector<ll> v(n);
    each(i, v)
        cin >> i, pq.push(i);
    while (pq.size()) {
        ll mn = pq.top();
        pq.pop();
        print(mn, accu, mn-accu);
        chmax(mx, mn-accu);
        accu += mn-accu;
    }
    cout << mx;
    
}