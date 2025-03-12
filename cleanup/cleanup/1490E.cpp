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
    vector<ll> v(n), arr;
    vector<int> ord(n);
    each(i, v)
        cin >> i;
    
    iota(all(ord), 1);
    sort(all(ord), [&](int a, int b){
        return v[a-1] < v[b-1];
    });
    print(v);
    print(ord);
    sort(all(v));
    arr = v;
    set<int> ans;
    for (int i = 1; i<n; i++)
        v[i] += v[i-1];
    for (int i = 0; i<n; i++){
        int l = i+1, r = n-1, m, res = i;
        ll curr = v[i];
        while(l<=r){
            m = (l+r)>>1;
            if (curr >= arr[m]) {
                curr = v[m];
                l = m+1;
                r = n-1;
                res = m;
            } else r = m-1;
        }
        print(i, curr, res);
        if (res == n-1)
            ans.insert(ord[i]);
    }
    // ans.insert(ord[n-1]);
    print(ans);
    cout << ans.size() << '\n';
    each(i, ans)
        cout << i << ' ';
}