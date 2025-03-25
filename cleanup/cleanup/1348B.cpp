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
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<31);
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
    int n, k; cin >> n >> k;
    set<int> frq;
    vector<int> v(n);
    getv(v);
    vector<int> unique, complete_k;
    each(i, v)
        if (!frq.count(i))
            unique.push_back(i), frq.insert(i);
    if ((int) frq.size() > k)
        kill(-1);
    for (int i = 0; i<k; i++) 
        complete_k.push_back(unique[i%(int)unique.size()]);
    cout << 10000 << '\n';
    for (int i = 0; i<(int)1e4; i++)
        cout << complete_k[i%(int)complete_k.size()] << ' ';
}