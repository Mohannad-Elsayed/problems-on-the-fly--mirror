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
    // cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, mxa, mxb; string s; cin >> n >> s;
    set<int> a, b;
    for (int i = 1; i <= n; i++)
        (s[i-1] == 'A' ? a : b).insert(i);
    print(a);
    print(b);
    while(a.size() && b.size()) {
        if (a.size() == 1 && b.size() == 1)
            kill((*a.begin() == 1 ? "Alice" : "Bob"));
        if (a.size() == 1)
            kill("Bob");
        if (b.size() == 1)
            kill("Alice");
        mxa = *a.rbegin();
        mxb = *b.rbegin();
        print(mxa, mxb);
        auto ita = a.upper_bound(mxb);
        auto itb = b.upper_bound(mxa);
        if (ita != a.end()) {
            if ((((*ita != n) || (*ita == n && a.count(1))) || 
            (*prev(ita) > mxb))) {
                a.insert(mxb);
                b.erase(mxb);
            }
            else {
                b.insert(mxa);
                a.erase(mxa);
            }
        } 
        else if (itb != b.end()) {
            if ((((*itb != n) || (*itb == n && b.count(1))) || 
            (*prev(itb) > mxa))) {
                b.insert(mxa);
                a.erase(mxa);
            }
            else {
                a.insert(mxb);
                b.erase(mxb);
            }
        } 
        print(a, b);
    }
    cout << (a.size() ? "Alice" : "Bob");
}