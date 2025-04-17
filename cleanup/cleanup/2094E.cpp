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
    int n, mx = -1, curr; cin >> n;
    vector<int> v(n), cnt(30), pfx(n);
    getv(v);
    pfx[0] = v[0];
    for (int i = 1; i < n; i++) 
        pfx[i] += v[i] + pfx[i-1];
    print(pfx);
    // each(i, v) {
    //     int ans = 0;
    //     each(x, v)
    //         ans += i^x;
    //     print(i, ans);
    //     print(bitset<30>(i));
    //     if (chmax(mx, ans))
    //         mxi = i;
    // }
    // print(mx, mxi);
    // int val = accumulate(all(v), 0ll, [&](int a, int b){return a^b;});
    // print(bitset<30>(accumulate(all(v), 0ll, [&](int a, int b){return a^b;})));
    // print(val);
    // int sum = 0;
    // for (int i = 0; i<30; i++)
    //     if ((1 << i) & val)
    //         sum += (1 << i);
    // print(sum);
    each(val, v) 
        for (int i = 0; i<30; i++) 
            cnt[i] += ((val >> i) & 1);
    
    auto stress = [&]() {
        int currneg = 0;
        for (int i = 29; ~i; i--) {
            int cnt0 = 0, cnt1 = 0;
            each(e, v) {
                if (e != -1 && ((1 << i) & e))
                    cnt1++;
                else
                    cnt0++;
            }
            if (cnt0 == n || cnt1 == n)
                continue;
            if (cnt0 < cnt1) {
                each(e, v) {
                    if (((1 << i) & e) && ~e && currneg+1 < n)
                        e = -1;
                }
            } else if (cnt0 > cnt1) {
                each(e, v) {
                    if ((!((1 << i) & e)) && ~e && currneg+1 < n)
                        e = -1;
                }
            }
            print(i, cnt0, cnt1);
            print(v);
        }
    };
    // print(v);

    each(val, v) {
        curr = 0;
        for (int i = 0; i<30; i++) 
            if ((val >> i) & 1) 
                curr += cnt[i] * (1 << i);
        curr = n * val + pfx.back() - 2*curr;
        chmax(mx, curr);
    }
    cout << mx;
}


/*

[i, bts]: 4  00100000000000000000
[i, bts]: 5  10100000000000000000


*/