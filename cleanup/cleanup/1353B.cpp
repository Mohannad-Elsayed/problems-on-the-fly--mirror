#define ONLINE_JUDGE
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
template<class T> void getv(T& v) {each(i, v)cin>>i;}
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
    int n, k; cin >> n >>k;
    deque<int> a(n), b(n);
    getv(a);
    getv(b);
    sort(all(a));
    sort(all(b));
    print(a);
    print(b);
    int i = 0;
    int sum = 0;
    while(k--) {
        if (a.front() > b.back())
            break;
        sum += b.back();
        a.pop_front();
        b.pop_back();
    }
    print(accumulate(all(a), sum));
    cout << accumulate(all(a), sum);
}