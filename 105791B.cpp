#define ONLINE_JUDGE
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
uniform_int_distribution<> uid(1, 1ll<<31);
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
using ld = long double;
ld distance(ld x1, ld x2, ld y1, ld y2) {
    // print(x1, x2, y1, y2);
    return sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
ld eps = 1e-4;
void solve() {
    ll n;
    ld k; 
    cin >> n >> k;
    vector<pair<ld, ld>> ps(n); // points, x, y
    each(p, ps)
        cin >> p.first >> p.second;
    ld dis_so_far = 0, ans = ps[0].second;
    for (int i = 1; i<n; i++) {
        ld dist = distance(ps[i].first, ps[i-1].first, ps[i].second, ps[i-1].second);
        if (dis_so_far+dist-k > eps) {
            ld lstpx = ps[i-1].first, lstpy = ps[i-1].second;
            ld curpx = ps[i].first, curpy = ps[i].second;
            print(lstpx, lstpy);
            print(curpx, curpy);
            // y = m x + c
            ld m = (curpy-lstpy) / (curpx-lstpx);
            // if (m < 0)
            //     break;
            ld c = lstpy - m * lstpx;
            ld l = 0, r = curpx-lstpx+1, mid;
            print(m, c);
            print(l, r);
            for (int i = 0; i<64; i++) {
                mid = (l+r)/2;
                ld mx = mid+lstpx;
                ld my = m * mx + c;
                print(mx, my);
                if (distance(lstpx, mx, lstpy, my) + dis_so_far <= k)
                    l = mid;
                else r = mid;
            }
            print("after", l, r);

            chmax(ans, m * (lstpx+l) + c);
            break;
        }
        dis_so_far += dist;
        chmax(ans, (ld)ps[i].second);
        print(i, dis_so_far); 
    }
    cout << fixed << setprecision(12);
    cout << ans;
}