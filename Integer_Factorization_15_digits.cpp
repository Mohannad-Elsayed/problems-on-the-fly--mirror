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
using vl = vector<ll>;
vl primeFactorsOf(ll n) { vl res; while (n % 2 == 0) { res.push_back(2); n /= 2; } for (ll i = 3; i * i <= n; i += 2) while (n % i == 0) { res.push_back(i); n /= i; } if (n > 1) res.push_back(n); return res; }
#define int ll

using mpii = map<int, int>;

void solve() {
    ll n;
    while (cin >> n && n != 0)
    {
        if (n == 0)
            break;
        vl f = primeFactorsOf(n);
        mpii mp;

        for (ll i = 0; i < f.size(); i++)
            mp[f[i]]++;

        vector<pair<int, int>> vp(all(mp));
        for (int i = 0; i+1 < vp.size(); i++) 
            cout << vp[i].first << '^' << vp[i].second << ' ';
        cout << vp.back().first << '^' << vp.back().second << '\n';
        // cout << "\n";
    }
}   