// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
struct range{
    int s, t, e;
    range(int a, int b, int c) : s(a), t(b), e(c){};
    friend ostream& operator << (ostream& o, range& r){
        o << r.s << ' ' << r.t << ' ' << r.e << '\n';
        return o;
    }
};
void solve(){
    int n, q; cin >> n >> q;
    vector<range> vr;
    for (int i = 0; i<q; i++){
        int a, b, t;
        string tt;
        cin >> a >> b >> tt;
        t = (tt == "even" ? 0 : 1);
        vr.push_back(range(a, b, t));
    }
    each(i, vr)
        cout << i;
    print("---");
    sort(all(vr), [&](range a, range b){
        return a.s < b.s;
    });
    int c = 1;
    for (int i = 0; i<q; i++){
        vr[i].s = c;
        if (i+1 < n && vr[i].s != vr[i+1].s)
            c++;
    }
    sort(all(vr), [&](range a, range b){
        return a.t < b.t;
    });
    c = 1;
    for (int i = 0; i<q; i++){
        vr[i].t = c;
        if (i+1 < n && vr[i].t != vr[i+1].t)
            c++;
    }
    each(i, vr)
        cout << i;
}