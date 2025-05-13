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
    // freopen("area.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
#define int ll
template<class T>
array<ll, 3> kadane(const vector<T>& arr) {
    ll mx = LLONG_MIN, csum = 0;
    ll s = 0, e = 0, ts = 0, sz = arr.size();
    for (ll i = 0; i < sz; i++) {
        if (csum + arr[i] > arr[i]) {
            csum += arr[i];
        } else {
            csum = arr[i];
            ts = i;
        }
        if (csum > mx) {
            mx = csum;
            s = ts;
            e = i;
        }
    }
    return {mx, s, e};
}
void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> v(n);
    getv(v);
    int sum = 0;
    // print(kadane(v));
    // int mn = -1e10, cnt = count(all(s), '0');
    // for (int i = 0, j = 0; i<n && j+1 < cnt; i++) {
    //     if (s[i] == '0') {
    //         v[i] = mn;
    //     }
    // }
    // for (int i = n-1; ~i; i--) {
    //     if (s[i] == '0') {
    //         v[i] = k - sum;
    //         break;
    //     }
    // }
    // print(v);
    // print(kadane(v));
    // for (int i = 0; i<n; i++) {
    //     if (s[i] == '0') {
    //         for (int j = 0; j < 1000; j++) {
    //             v[i] = j;
    //             print(j, kadane(v));
    //             // print(accumulate(v.begin() + kadane(v)[1], v.begin()+kadane(v)[2]+1, 0ll));
    //         }
    //         break;
    //     }
    // }

    auto mxsub = kadane(v);
    int mxsubsum = mxsub[0];
    int l = -1e18, r = 1e18, mid, res = -1;
    int f0 = -1;
    for (int i = 0; i<n; i++) {
        if (s[i] == '0') {
            f0 = i;
            break;
        }
    }
    for (int i = f0+1; i < n; i++)
        if (s[i] == '0')
            v[i] = -1e12;

    auto check = [&](int m) -> bool {
        v[f0] = m;
        int currmxsum = kadane(v)[0];
        print(v, currmxsum);
        return currmxsum >= k;
    };
    if (f0 == -1) {
        if (mxsubsum == k) {
            cout << "YES\n";
            each(i, v)
                cout << i << ' ';
            return;
        }
        kill("NO");
    }
    while(l <= r) {
        mid = l + (r-l)/2;
        if (check(mid)) {
            res = mid;
            r = mid-1;
        } else l = mid+1;
    }
    v[f0] = res;
    if (kadane(v)[0] != k) {
        kill("NO");
    }
    cout << "YES\n";
    each(i, v)
        cout << i << ' ';
}


/*
10
3 5
011
0 0 1

5 6
11011
4 -3 0 -2 1

4 4
0011
0 0 -4 -5

6 12
110111
1 2 0 5 -1 9

5 19
00000
0 0 0 0 0

5 19
11001
-8 6 0 0 -5

5 10
10101
10 0 10 0 10

1 1
1
0

3 5
111
3 -1 3

4 5
1011
-2 0 1 -5


*/