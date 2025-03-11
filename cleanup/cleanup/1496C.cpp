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
using ld = long double;
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
    cout << fixed << setprecision(20);
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
void solve() {
    int n; cin >> n;
    vector<int> xs, ys;
    n *= 2;
    while(n--){
        int a, b;
        cin >> a >> b;
        if (a)
            ys.push_back(abs(a));
        else
            xs.push_back(abs(b));
    }
    sort(rall(xs));
    sort(rall(ys));
    print(xs);
    print(ys);
    ld ans = 0;
    while(xs.size()) {
        int a = xs.back();
        xs.pop_back();
        int b = ys.back();
        ys.pop_back();
        ans += sqrtl(a*a + b*b);
    }
    print(ans);
    cout << ans;
}