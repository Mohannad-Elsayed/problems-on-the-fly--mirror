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
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n; string s; 
    cin >> n >> s;
    int starcnt = 0;
    n = s.size();
    vector<int> indices;
    for (int i = 0; i<n; i++)
        if (s[i] == '*')
            indices.push_back(i);
    if (indices.size() < 2 || indices.size() == n)
        kill(0);
    for (int i = 0; i<indices.size(); i++)
        indices[i] -= i;
    print(indices);

    int target = indices[indices.size()/2];
    print(target);

    ll ans = 0;
    each(i, indices)
        ans += abs(i-target);
    cout << ans;
}