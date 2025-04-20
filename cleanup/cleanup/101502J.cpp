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
    int n, f = 1, F = 0, S = 0; cin >> n;
    deque<int> dq(n);
    getv(dq);
    while(dq.size()) {
        if (dq.size() == 1) {
            (f ? F : S) += dq.front();
            dq.pop_back();
        }
        else if (dq[1] == dq[dq.size() - 2]) {
            if (dq.front() > dq.back()) {
                (f ? F : S) += dq.front();
                dq.pop_front();
            } else {
                (f ? F : S) += dq.back();
                dq.pop_back();
            }
        }
        else if (dq[1] > dq[dq.size() - 2]) {
            (f ? F : S) += dq.back();
            dq.pop_back();
        }
        else {
            (f ? F : S) += dq.front();
            dq.pop_front();
        }
        f ^= 1;
    }
    // print(F, S);
    cout << F - S;
}   