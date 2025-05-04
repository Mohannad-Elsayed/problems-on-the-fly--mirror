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
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int ask(int x) {
    cout << "? " << x << endl;
    cout.flush();
    int ret;
    cin >> ret;
    if (ret == -1)
        exit(0);
    return ret;
}
void solve() {
    int n, k; cin >> n >> k;
    bool f = 1;
    if (false) {
        // request all and check them using bruteforce
        vector<int> v(n);
        for (int i = 0; i<n; i++) {
            v[i] = ask(i+1);
        }
        map<int, int> mp; // number, freq
        int cnt = 0;
        for (int i = 0; i+k-1<n; i++) {
            mp.clear();
            bool valid = true;
            for (int j = i; j < i+k; j++) {
                if (mp.count(v[j])) {
                    valid = false;
                    break;
                }
                mp[v[j]] = 1;
            }
            cnt += valid;
        }
        if (cnt != n-k+1)
            f = 0;
        if (f) {
            cout << "! " << k << ' ' << n-k << endl;
            cout.flush();
        } else {
            cout << "! " << -1 << endl;
            cout.flush();
        }
    } else {
        // request first and last k, if all unique output k, n-k
        set<int> ste1, ste2;
        for (int i = 0; i<k; i++) {
            int a = ask(i+1);
            ste1.insert(a);
            a = ask(n-i-1);
            ste2.insert(a);
        }
        if (ste1.size() == k && ste2.size() == k) {
            cout << "! " << k << ' ' << n-k << endl;
            cout.flush();
        } else {
            cout << "! " << -1 << endl;
            cout.flush();
        }
    }
}