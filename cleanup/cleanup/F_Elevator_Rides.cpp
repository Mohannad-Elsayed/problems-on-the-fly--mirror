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
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

#define int ll
void solve(){
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    each(i, v)
        cin >> i;
    // print(v);
    sort(all(v));
    int cnt = 0;
    while(v.size()){
        ll mxsz = -1, currsz, np = 0;
        vector<int> indices, currindices;
        int sz = v.size();
        for (int i = 1; i < (1 << sz); i++){
            currsz = np = 0;
            currindices.resize(0);
            for (int k = 0; k < sz; k++){
                if ((i >> k) & 1){
                    currsz += v[k];
                    np++;
                    currindices.push_back(k);
                }
            }
            // print(currsz);
            // print(currindices);
            if (currsz > mxsz && currsz <= x){
                indices = currindices;
                mxsz = currsz;
            }
        }
        print(mxsz);
        print(indices);

        cout << "vector: ";
        each(i, indices){
            cout << v[i] << ' ';
        } cout << "\n\n";

        cnt++;
        each(i, indices)
            v[i] = -1;
        sort(rall(v));
        while(v.back() == -1)
            v.pop_back();
    }
    cout << cnt;
}