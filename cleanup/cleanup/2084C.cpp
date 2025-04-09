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
uniform_int_distribution<> uid(1, 1ll<<30);
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
    int n; cin >> n;
    vector<int> a(n), b(n), inda(n+1), indb(n+1);
    getv(a);
    getv(b);
    for (int i = 0; i<n; i++) {
        inda[a[i]] = i;
        indb[b[i]] = i;
    }
    print(inda);
    print(indb);
    vector<int> op1, op2;
    auto swapv = [&](int i, int j) {
        if (i == j)
            return;
        inda[a[i]] = j;
        inda[a[j]] = i;
        swap(a[i], a[j]);
        indb[b[i]] = j;
        indb[b[j]] = i;
        swap(b[i], b[j]);
        op1.push_back(i+1);
        op2.push_back(j+1);
    };
    for (int i = 0; i<n; i++) {
        if (inda[a[i]] == indb[a[i]]) {
            if (n % 2 == 0)
                kill(-1);
            if (i != n/2);
                swapv(i, n/2);
        }
    }
    for (int i = 0; i<n; i++) {
        print(i);
        print(a);
        print(b);
        // if (inda[a[i]] == indb[a[i]]) {
        //     if (n % 2 == 0)
        //         kill(-1);
        //     swapv(i, n/2);
        // }
        if (indb[a[i]] != n-i-1) {
            swapv(indb[a[i]], n-i-1);
        }
    }
    print(n);
    print(a);
    print(b);
    for (int i = 0; i<n; i++) {
        if (a[i] != b[n-i-1]) {
            kill(-1);
        }
    }
    // // assert((int) op1.size() <= n);
    cout << (int)op1.size() << '\n';
    for (int i = 0;i<(int)op1.size(); i++) 
        cout << op1[i] << ' ' << op2[i] << '\n';
}