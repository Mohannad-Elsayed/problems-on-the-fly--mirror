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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void stress() {
    int a, b, c, d, e, mx = 0;
    cin >> a >> b >> c >> d >> e;
    vector<int> frq(1000), sums(1), sums2;
    while(a--) {
        for (int i = 1; i <= 4; i++) {
            each(ss, sums) {
                sums2.push_back(i+ss);
            }
        }
        sums = sums2;
        sums2.clear();
    }
    // print(sums);
    while(b--) {
        for (int i = 1; i <= 6; i++) {
            each(ss, sums) {
                sums2.push_back(i+ss);
            }
        }
        sums = sums2;
        sums2.clear();
    }
    // print(sums);
    while(c--) {
        for (int i = 1; i <= 8; i++) {
            each(ss, sums) {
                sums2.push_back(i+ss);
            }
        }
        sums = sums2;
        sums2.clear();
    }
    // print(sums);
    while(d--) {
        for (int i = 1; i <= 12; i++) {
            each(ss, sums) {
                sums2.push_back(i+ss);
            }
        }
        sums = sums2;
        sums2.clear();
    }
    // print(sums);
    while(e--) {
        for (int i = 1; i <= 20; i++) {
            each(ss, sums) {
                sums2.push_back(i+ss);
            }
        }
        sums = sums2;
        sums2.clear();
    }
    print(sums.size());
    each(i, sums)
        frq[i]++;
    int cc = 0;
    for (int i = 1; i < 1000; i++) {
        if (frq[i]) {
            print(i, frq[i]);
            cc++;
        }
    }
    print(cc);
}

void solve() {
    // stress();return;
    int a, b, c, d, e, mx, mn, l, r;
    cin >> a >> b >> c >> d >> e;
    mx = a*4+b*6+c*8+d*12+e*20;
    mn = a+b+c+d+e;
    // print(mn, mx);
    l = (mx-mn)/2+mn, r = (mx-mn+1)/2+mn;
    // print(l, r);
    while(l >= mn || r <= mx) {
        if (l >= mn)
            cout << l << ' ';
        if (l != r && r <= mx)
            cout << r << ' ';
        l--, r++;
    }
}