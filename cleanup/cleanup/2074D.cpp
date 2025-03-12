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
using ld  = long double;
const ld pi = acosl(-1);
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

#define int ll
void solve() {
    int n, m; cin >> n >> m;
    vector<int> rad(n), pos(n), sortedradsq;
    each(i, pos)
        cin >> i;
    each(i, rad)
        cin >> i;
    vector<pair<int, int>> vp; // position - radius
    for (int i = 0; i<n;i++)
        vp.emplace_back(pos[i], rad[i]);
    sortedradsq = rad;
    sort(all(sortedradsq));
    each(i, sortedradsq)
        i *= i;
    
    sort(all(vp), [&](pair<int, int> a, pair<int, int> b){
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });
    print(vp);
    int lastposition = vp[0].first-vp[0].second-1;
    print(sortedradsq);
    int ans = 0;
    for (int i = 0; i<n; i++){
        int rangel = max(lastposition, vp[i].first-vp[i].second);
        int ranger = vp[i].first+vp[i].second;
        if (ranger <= lastposition)
            continue;
        int xi = vp[i].first, radius = vp[i].second;
        for (int ir = rangel; ir < ranger; ir++) {
            int l = 0, r = 1e6, m, res = 0;
            while(l <= r) {
                m = (l+r)>>1; // y
                // print(xi, ir, m, (xi - ir) * (xi - ir));
                bool shart = lower_bound(all(sortedradsq), ((xi - ir) * (xi - ir)) + m*m) != sortedradsq.end();
                bool shart2 = ((xi - ir) * (xi - ir)) + m*m <= radius * radius;
                // print(shart);
                // search for a value that greater than 
                // if (lower_bound(all(sortedradsq), ((xi - ir) * (xi - ir)) + m*m) != sortedradsq.end()) {
                if (shart2) {
                    res = m;
                    l = m+1;
                } else r = m-1;
            }
            ans += res*2+1;
            print(ir, res, ans);
        }
        lastposition = ranger-1;
    }
    cout << ans;

}