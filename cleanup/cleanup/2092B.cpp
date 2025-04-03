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
    int n; string a, b, c1, c2; cin >> n >> a >> b;
    if (a == string(n, '0'))
        kill("YES");
    for (int i = 0; i<n; i++) {
        if (i%2 == 0) 
            c1.push_back(a[i]), c2.push_back(b[i]);
        else
            c2.push_back(a[i]), c1.push_back(b[i]);
    }
    print(c1, c2);
    if (count(all(c1), '1') > n/2)
        kill("NO");
    if (count(all(c2), '1') > (n+1)/2)
        kill("NO");
    cout << "YES";
}