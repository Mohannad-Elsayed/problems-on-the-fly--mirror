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
    set<int> stemex;
    for (int i = 0; i<=n+1; i++)
        stemex.insert(i);
    
    vector<int> v(n), ans, suff(n);
    each(i, v)
        cin >> i;
    for (int i = n-1; ~i; i--) {
        stemex.erase(v[i]);
        suff.at(i) = *stemex.begin();
    }
    print(suff);
    
    for (int i = 0; i<=n+1; i++)
        stemex.insert(i);
    
    for (int i = 0; i<n;) {
        int lst = i;
        for (; lst < n; lst++) {
            stemex.erase(v[lst]);
            if (*stemex.begin() == suff[i])
                break;
        }
        ans.push_back(suff[i]);
        for (;i<=lst;i++)
            stemex.insert(v[i]);
        print(i, lst, ans);
    }
    cout << ans.size() << '\n';
    each(i, ans)
        cout << i << ' ';
}