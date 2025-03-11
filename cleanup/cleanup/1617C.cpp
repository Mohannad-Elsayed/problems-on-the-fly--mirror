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

void solve() {
    int n; cin >> n;
    vector<int> v(n), have;
    each(i, v)
        cin >> i;
    sort(rall(v));
    set<int, greater<int>> perm;
    for (int i = n; i > 0; i--)
        perm.insert(i);
    // print(perm);
    each(i, v)
        if (perm.count(i))
            perm.erase(i);
        else have.push_back(i);
    int ans = perm.size();
    // print(ans, v.size());
    print(perm);
    print(have);
    for (int i = 0; i<ans; i++){
        if ((have[i]-1)/2 < *perm.begin())
            kill(-1);
        perm.erase(perm.begin());
    }
    print(perm);
    print(v);
    cout << ans;
}