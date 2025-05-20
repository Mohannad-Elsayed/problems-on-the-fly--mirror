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
template<class T>
class mex_calculator {
    map<T, T> count;
    set<T> missing;
    public:
    mex_calculator() {}
    mex_calculator(const vector<T>& arr, T upper_bound) {
        for (T x : arr)
            count[x]++;
        count[0]++;
        for (T i = 0; i <= upper_bound + 1; ++i)
            if (count[i] == 0)
                missing.insert(i);
    }
    void insert(T x) {
        count[x]++;
        if (count[x] == 1)
            missing.erase(x);
    }
    void erase(T x) {
        if (count[x] == 0) return;
        count[x]--;
        if (count[x] == 0)
            missing.insert(x);
    }
    T get_mex() {
        return *missing.begin();
    }
};
void stress() {
    for (int n = 1; n < 11; n++) {
        int ans = 0;
        vector<int> v(n+1);
        iota(all(v), 0);
        // print(v);
        mex_calculator<int> mc(v, n);
        while (v.size() > 1) {
            int med = (v.size())/2;
            // print(v[med]);
            mc.erase(v[med]);
            v.erase(v.begin()+med);
            ans += mc.get_mex();
            // print(mc.get_mex());
        }
        print(n, ans);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("area.in", "r", stdin);
    // stress();
    // exit(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    ll n; cin >> n;
    n++;
    cout << n * n/4;
}