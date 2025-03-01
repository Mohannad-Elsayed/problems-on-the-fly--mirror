#define LOCAL
#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
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

    #ifndef LOCAL
        freopen("helpcross.in", "rt", stdin);
        freopen("helpcross.out", "wt", stdout);
    #endif

    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

struct interval {
    int st, en;
    interval(){};
    interval(int a, int b) : st(a), en(b) {}
    bool operator<(const interval &b) const {
        if (st != b.st)
            return st > b.st;
        return en < b.en;
    }
};
string to_string(interval i){
    return "{ " + to_string(i.st) + " : " + to_string(i.en) + " }\n";
}
void solve(){
    int n, q, t, cnt = 0; cin >> n >> q;
    vector<int> v(n);
    multiset<pair<int, int>> mste; // end, start;
    each(i, v)
        cin >> i;
    
    for (int i = 0; i<q; i++){
        pair<int, int> cow;
        cin >> cow.second >> cow.first;
        mste.insert(cow);
    }

    sort(all(v));

    each(ch, v){
        auto it = mste.lower_bound(make_pair(ch, -1));

        if (it != mste.end())
            print("n", ch, *it);

        if (it != mste.end() && it->second <= ch){
            print((*it));
            cnt++;
            mste.erase(it);
        }
    }
    cout << cnt;
}