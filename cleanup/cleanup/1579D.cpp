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
template <class T>
using mxpq = priority_queue<T>;

void printpq(auto p){
    while(p.size()){
        print(p.top());
        p.pop();
    }
}
void solve() {
    int n; cin >> n;
    mxpq<pair<int, int>> pq;
    for (int i = 0; i<n; i++){
        int score; cin >> score;
        if (score)
            pq.push(make_pair(score, i+1));
    }
    vector<pair<int, int>> ans;
    while(pq.size() > 1){
        // printpq(pq);
        print("|");
        auto [sca, ida] = pq.top();
        pq.pop();
        auto [scb, idb] = pq.top();
        pq.pop();
        ans.emplace_back(ida, idb);
        if (sca > 1)
            pq.push(make_pair(sca-1, ida));
        if (scb > 1)
            pq.push(make_pair(scb-1, idb));
        
    }
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans)
        cout << x << ' ' << y << '\n';
}