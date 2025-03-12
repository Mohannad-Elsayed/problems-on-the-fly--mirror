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
set<int> uste;
vector<int> vals;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    int n = 1;
    for (int i = 1; i < 32; i++, n <<= 1) {
        uste.insert(n);
        uste.insert(n-1);
        vals.push_back(n);
        vals.push_back(n-1);
        vals.push_back(n+1);
    }
    // print(uste);
    // exit(0);

    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
bool check(int a, int b, int c){
    return (a+b > c && a+c > b && b+c > a);
}
using ld = long double;
void solve() {
    // freopen("hack4.txt", "wt", stdout);
    // ll x; cin >> x;
    // if (uste.count(x))
    //     kill(-1);
    int cnt = 0;
    set<int> ste;
    map<int, vector<int>> mp;
    ld currmin = 1e9;
    int sssss = -1, mxdis = -1;
    for (int k = 1; k < 1000000000; k++) {
        cnt = k;
        for (int i = k; i > 1; i--) {
            if (check(k, i, k^i)) {
                // print(k, i, k^i);
                // ste.insert(i);
                // if (i > 100000 && k <= int(1e6))
                //     mp[i].push_back(k);
                // printBinary(k);
                // printBinary(i);
                // printBinary(i^k);
                cnt = i;
                break;
            }
        }
            // print(k, cnt);
            // if (cnt && ld(cnt)/k < currmin)
            //     currmin = ld(cnt)/k, sssss = k;
        if (k - cnt > mxdis)
            mxdis = k-cnt, sssss = k;
    }
    // print(ste);
    // print(mp);
    // int ccnt = 0;
    // each(i, mp)
    //     ccnt += i.second.size();
    // print(ccnt);
    // cout << ccnt << '\n';
    // each(i, mp)
    //     each(vv, i.second)
    //         cout << vv << '\n';
    print(sssss, mxdis);
    // auto it = mp.rbegin();
    // cout << it->first << '\n';
    // print(it->second);
    // sort(all(vals));
    // each(val, vals) {
    //     if (val < x && check(val, x, val^x))
    //         kill(val);
    // }
}