// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
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
int rnglr(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
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
    string a, b, x, y; 
    cin >> a >> b;
    reverse(all(a));
    reverse(all(b));
    while(a.size() && b.size()) {
        x.clear(); y.clear();
        while(x.empty() || x.back() == a.back()) {
            x.push_back(a.back());
            a.pop_back();
        }
        while(y.empty() || y.back() == b.back()) {
            y.push_back(b.back());
            b.pop_back();
        }
        // print(x); // actual
        // print(y); // heard >= actual
        if ((y.size() < x.size()) || (y.size() > 2*x.size()))
            kill("NO");
        if (y.front() != x.front())
            kill("NO");
    }
    if (a.size() || b.size())
        kill("NO");
    cout << "YES";
}