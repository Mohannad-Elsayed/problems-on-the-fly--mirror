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
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;

    // freopen("out.out", "rt", stdin);
    // freopen("in.in", "wt", stdout);

    // int N = 100;
    // for (int i = -N; i <= N; i++){
    //     for (int j = -N; j <= N; j++)
    //         cout << i << ' ' << j << '\n';
    // }
    // exit(0);
    
    cin >> tt;
    // cout << tt << '\n';
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int x, y;
    cin >> x >> y;
    int a, b, c = -1, d = -1;
    int rangab = 2*x, rangcd = 2*y;
    set<int> ste;
    for (int i = -200; i <= 200; i++){
        // if (ste.count(i) || ste.count(rangab-i));
        //     continue;
        if (rangab-i > 200 || rangab-i < -200)
            continue;
        if (i == rangab-i)
            continue;
        
        ste.insert(i);
        ste.insert(rangab-i);
        break;
    }
    assert(ste.size());
    a = *ste.begin();
    b = *ste.rbegin();

    print(ste);
    for (int i = -200; i <= 200; i++){
        print(i, rangcd, rangcd-i);
        if (ste.count(i) || ste.count(rangcd-i))
            continue;
        if (rangcd-i > 200 || rangcd-i < -200)
            continue;
        if (i == rangcd-i)
            continue;
        
        c = i;
        d = rangcd-i;
        break;
    }
    // print(c, d);
    cout << a << ' ' << b << ' ' << c << ' ' << d;

}