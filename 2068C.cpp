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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    each(i, v)
        cin >> i;
    int csum = 0, cvid = 0, ans = 0;
    sort(all(v));
    // print(v);
    for (int i = 0; i+1<(int) v.size();){
        vector<int> vv(v.begin()+i, v.end());
        print(vv);
        if (csum + v[i] > k || cvid == 2){
            ans++;
            csum = cvid = 0;
            v.pop_back();
        }
        else {
            csum += v[i];
            cvid++;
            i++;
        }
    }
    print(ans);
    cout << ans;
}