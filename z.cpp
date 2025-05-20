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

template<typename T>
struct sparse_table {
    vector<vector<T>> st;
    int n, logn;
    function<T(T, T)> merge;
    T skip;
    sparse_table(const vector<T>& a, function<T(T, T)> f, T skip = T())
        : n(a.size()), merge(f), skip(skip) {
        logn = 32 - __builtin_clz(n);
        st.assign(logn, vector<T>(n));
        st[0] = a;
        for (int k = 1; k < logn; ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                st[k][i] = merge(st[k-1][i], st[k-1][i + (1 << (k-1))]);
    }
    T query(int l, int r) { // [l, r]
        int k = 31 - __builtin_clz(r - l + 1);
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }
    T query_nonid(int l, int r) {
        T res = skip;
        for (int k = logn-1; k >= 0; --k)
            if ((1 << k) <= r - l + 1)
                res = merge(res, st[k][l]), l += 1 << k;
        return res;
    }
};

void solve() {
    vector<int> v {1,2,3,4,1,2,3,4,3,4,3,4};
    function<int(int, int)> su = [&](int a, int b) {
        return a^b;
    };
    sparse_table<int> sp(v, su, 0);
    cout << sp.query_nonid(0, 3);
}