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

int ask(int a, int b, int c) {         
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    cout.flush();
    int val; 
    cin >> val;
    if (val == -1)
        exit(0);
    return val;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int n; cin >> n;
    vector<int> v {1, 2, 3};
    int i = 0;
    int q = 0;
    while(q <= 75) {
        int a = v[0], 
        b = v[1],
        c = v[2];
        int val = ask(a, b, c);
        if (!val) {
            cout << "! " << a << ' ' << b << ' ' << c << endl;
            cout.flush();
            return;
        }
        v[rng()%3] = val;
        i++;
        i %= 3;
    }
    assert(false);
    exit(0);
}