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
int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    int val;
    cin >> val;
    if (val == -1)
        exit(0);
    return val;
}
void solve() {
    int L = 2, R = 999;
    while(L < R) {
        if (L+1 == R){
            int v = ask(1, L);
            if (v == L)
                L++;
            break;
        }
        else {
            int m1 = L + (R-L)/3;
            int m2 = R - (R-L)/3;
            int v = ask(m1, m2);
            if (v == m1*m2) {
                // (m2, R]
                L = m2+1;
            }
            else if (v == m1 * (m2+1)) {
                // (m1, m2]
                L = m1+1;
                R = m2;
            } else {
                // [L, m1]
                R = m1;
            }
        }
    }
    cout << "! " << L;
}