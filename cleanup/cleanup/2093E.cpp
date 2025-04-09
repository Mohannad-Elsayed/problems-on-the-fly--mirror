// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("cleanup/debug.h not found, or ONLINE_JUDGE defined.")
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
    int n, k, ans = 1e9, mxsize;
    cin >> n >> k;
    mxsize = n-k+1;
    set<int> mexes, nmexes;
    for (int i = 0; i<=mxsize+1; i++) {
        mexes.insert(i);
    }
    nmexes = mexes;
    vector<int> v(n);
    getv(v);

    auto check = [&](int mid) -> bool {
        int curr = 1e9;
        mexes = nmexes;
        map<int, int> del;
        for (int i = 0; i<mxsize; i++) {
            del[v[i]]++;
            mexes.erase(v[i]);
        }
        curr = *mexes.begin();
        for (int i = mxsize; i < n; i++) {
            del[v[i-mxsize]]--;
            del[v[i]]++;
            mexes.erase(v[i]);
            if (!del[v[i-mxsize]]) {
                mexes.insert(v[i-mxsize]);
            }
            chmin(curr, *mexes.begin());
        }
        return curr >= mid;
    };

    int l = 0, r = 3e5, m;
    while(l <= r) {
        m = (l+r) >> 1;
        if (check(m)) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }

    cout << ans;
}