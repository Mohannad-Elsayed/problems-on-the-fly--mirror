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
    int n; 
    cin >> n;
    vector<int> v(n), perm(n+1);
    each(i, v) {
        cin >> i;
        if (i >= 1 && i <= n)
            perm[i] = 1;
    }
    string s; cin >> s;
    multiset<int> blues;
    multiset<int, greater<>> reds;
    for (int i = 0; i<n; i++){
        if (s[i] == 'R') {
            if (v[i] > n)
                kill("NO");
            if (v[i] > 0 && v[i] <= n && !perm[v[i]])
                reds.insert(v[i]);
        }
        if (s[i] == 'B') {
            if (v[i] < 1)
                kill("NO");
            if (v[i] > 0 && v[i] <= n && !perm[v[i]])
                blues.insert(v[i]);
        }
    }
    print(reds);
    print(blues);
    for (int i = 1; i <= n; i++){
        if (perm[i])
            continue;
        auto itr = reds.lower_bound(i);
        auto itb = blues.lower_bound(i);
        print(i, itr != reds.end(), itb != blues.end());
        print(i, *itr, *itb);
        if (itr != reds.end() && itb != blues.end()){
            int rr = *itr, bb = *itb;
            if (abs(i-rr) > abs(i-bb)) {
                blues.erase(itb);
                continue;
            }
            else {
                reds.erase(itr);
                continue;
            }
        }
        if (itr != reds.end()) {
            reds.erase(itr);
            continue;
        }
        if (itb != blues.end()) {
            blues.erase(itb);
            continue;
        }
        kill("NO");
    }
    cout << "YES";
    
}