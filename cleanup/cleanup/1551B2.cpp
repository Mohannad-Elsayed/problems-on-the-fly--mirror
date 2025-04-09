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
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n), ans(n), p, cnt(n+1);
    for (int i = 0; i<n; i++){
        cin >> v[i];
        cnt[v[i]]++;
        if (cnt[v[i]] <= k)
            p.push_back(i);
        
    }
    // print(p.size());
    while(p.size()%k)
        p.pop_back();
    sort(all(p), [&](int i, int j){
        return v[i] > v[j];
    });
    for (int i = 0; i<p.size(); i++)
        ans[p[i]] = i%k + 1;
    each(i, ans)
        cout << i << ' ';
}