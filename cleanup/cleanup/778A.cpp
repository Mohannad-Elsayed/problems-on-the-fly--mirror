#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << (x), 0;
#define killn(x) return cout << (x) << '\n', 0;

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}
int solvebf(string a, string b, vector<int> v){
    print(a);
    print(b);
    for (int i = 0; i<v.size(); i++){
        int x = v[i] - 1;
        a[x] = '-';
        print(a);
        // --- 
        bool ok = false;
        for (int ai = 0, bi = 0; ai < a.size(); ai++){
            if (a[ai] == b[bi]){
                bi++;
                if (bi == b.size()){
                    ok = true;
                    break;
                }
            }
        }
        // ---

        if (!ok){
            cout << i;
            exit(0);
        }
    }
}
int solve(){
    string a, b; vector<tuple<char, int, int>> aa; 
    cin >> a >> b;
    vector<int> v(a.size());
    each(i, v)
        cin >> i;
    print(v);
    // solvebf(a, b, v);
    int n = a.size(), t;
    for (int i = 1; i<=n; i++)
        aa.push_back({a[v[i-1]-1], v[i-1], i});
    
    reverse(all(b));
    reverse(all(aa));
    // print(b);
    // print(aa);

    for (int i = 0, bi = 0, mn = 1e6; i<n; i++){
        auto [ch, idx, order] = aa[i];
        print(ch, idx, order);
        if (ch == b[bi] && (!bi || b[bi] == b[bi-1] || idx < mn)){
            bi++;
            mn = min(mn, idx);
            // print(aa[0]);
            print(b[bi], mn);
        }
        if (bi == (int)b.size()){
            kill(n-i-1);
        }
    }
    //________________________
    return 0;
}