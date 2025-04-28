// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnglr(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
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
#define int ll
void solve() {
    int n, m; 
    cin >> n >> m;
    vector<int> a(n), b(m), aa(m, n), bb(m, -1);
    getv(a);
    getv(b);
    // print(a);
    // print(b);
    // int j = 0, lasti = -1, mxx = 1e10;
    // for (int i = 0; i<n; i++) {
    //     if (a[i] >= b[j]) {
    //         j++;
    //         lasti = i;
    //         if (j == m) {
    //             kill(0);
    //         }
    //     }
    // }
    // multimap<int, int> mmp;
    // for (int i = 0; i<n; i++)
    //     mmp.insert({a[i], i});
    // // print(mmp);
    // for (int i = 1; i<=m; i++) {
    //     auto it = mmp.lower_bound(b[i-1]);
    //     if (it == mmp.end()) 
    //         bidx[i] = mxx;
    //     else {
    //         bidx[i] = it->second;
    //         // print(b[i-1], it->first, it->second);
    //         mmp.erase(it);
    //     }
    // }
    // bidx.back() = n;
    // print(bidx);
    // if (count(all(bidx), mxx) > 1) 
    //     kill(-1);
    // for (int i = 1; i <= m; i++) {
    //     if (bidx[i] > bidx[i+1]) {
    //         a.insert(a.begin()+bidx[i-1]+1, b[i-1]);
    //         int inserted = b[i-1];
    //         print(inserted);
    //         print(a);
    //         print(b);
    //         j = 0;
    //         for (int k = 0; k<=n; k++) {
    //             if (a[k] >= b[j]) {
    //                 j++;
    //                 lasti = k;
    //                 if (j == m) {
    //                     kill(inserted);
    //                 }
    //             }
    //         }
    //     kill(-1);
    //     }
    // }
    // kill(-1);
    // // vector<pair<int, int>> vp(n); // val, idx;
    // // for (int i = 0; i<n; i++) 
    // //     vp[i] = {a[i], i};
    // // print(vp);
    // // vector<int> idxes;
    // // sort(all(vp));
    // // auto it = lower_bound(all(vp), make_pair(b[0], 0ll));
    // // idxes.push_back(it != vp.end() ? it->second : n);
    // // for (int i = 1; i < m; i++) {
    // //     it = lower_bound(all(vp), make_pair(b[i], idxes.back()));
    // //     idxes.push_back(it != vp.end() ? it->second : n);
    // // }
    // // print(idxes);

    int j = 0;
    for (int i = 0; i<m; i++) {
        int k;
        for (k = j; k < n; k++) 
            if (a[k] >= b[i])
                break;
        
        if (k == n)
            break;
        j = k;
        aa[i] = j;
        j++;
    }
    if (aa.back() < n)
        kill(0);
    
    j = n-1;
    for(int i = m-1; ~i; i--) {
        int k;
        for (k = j; ~k; k--) 
            if (a[k] >= b[i])
                break;
        if (k == -1)
            break;
        j = k;
        bb[i] = j;
        j--;
    }
    print(aa);
    print(bb);
    auto check = [&](int mid) -> bool {
        // insert mid in any location, after mid use bb, before mid use aa
        for (int i = 0; i < m; i++) {
            if (mid < b[i])
                continue;
            int before, after;
            if (i > 0) {
                before  = aa[i-1];
            } else before  = -1;

            if (i + 1 < m) {
                after = bb[i+1];
            } else after = n;

            if (before < after)
                return true;
        }
        return false;
    };
    int l = 0, r = 1e16, mid, res = -1;
    while(l<=r) {
        mid = l+r >> 1;
        if (check(mid)) {
            res = mid;
            r = mid-1;
        } else l = mid+1;
    }
    cout << res;
}

/*
0 1 2 3 4 5 6 7 8
3 5 2 3 3 5 8 1 2

*/