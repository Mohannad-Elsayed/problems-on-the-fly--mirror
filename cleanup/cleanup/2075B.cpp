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
template<class T> void getv(T& v) {each(i, v)cin>>i;}
void solve();
pair<vector<int>, vector<int>> sort_with_indices(const vector<int>& arr) {
    vector<pair<int, int>> paired;
    for (int i = 0; i < arr.size(); ++i) {
        paired.emplace_back(arr[i], i);
    }
    sort(all(paired));
    vector<int> sorted_array, indices;
    for (const auto& p : paired) {
        sorted_array.push_back(p.first);
        indices.push_back(p.second);
    }
    return {sorted_array, indices};
}
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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    getv(v);
    ll sum = accumulate(all(v), 0ll);
    if (k == n-1)
        kill(sum);
    auto sortedPairIndicies = sort_with_indices(v);
    auto sorted = sortedPairIndicies.first;
    vector<int> indicies = sortedPairIndicies.second;
    if(sorted[n-1] == v[n-1] || sorted[n-1] == v[0] || k > 1){
        cout << accumulate(sorted.end() - k - 1, sorted.end(), 0ll);
    }
    else{
    cout << accumulate(sorted.end() - k, sorted.end(), 0ll) + max(v[0], v[n - 1]);
    }
    
}