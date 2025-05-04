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
    // freopen("pattern.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    string a, b;
    cin >> a >> b;
    a = '#' + a;
    b = '#' + b;
    // print(a, b);
    int n = a.size(), m = b.size();
    if (n < m) {
        print("all neg-1");
        for (int i = 1; i <= n; i++)
            cout << -1 << ' ';
        return;
    }
    vector<vector<int>> prefa(n, vector<int>(125));
    vector<vector<int>> prefb(m, vector<int>(125));
    for (int i = 1; i < n; i++) {
        prefa[i][a[i]]++;
    }
    for (int i = 1; i < m; i++) {
        prefb[i][b[i]]++;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            prefa[i][j] += prefa[i-1][j];
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            prefb[i][j] += prefb[i-1][j];
        }
    }

    map<char, int> pa, pb, tpb;
    for (char chc = 'a'; chc <= 'z'; chc++)
        if (prefb[m-1][chc])
            pb[chc] = prefb[m-1][chc];
    tpb = pb;

    for (int i = 1; i < n; i++) {
        int l = i+max(m-2, 0), r = n-1, mid, res = -1;
        while(l <= r) {
            mid = (l+r) / 2;
            // check
            
            for (char chc = 'a'; chc <= 'z'; chc++)
                if(prefa[mid][chc] - prefa[i-1][chc])
                    pa[chc] = prefa[mid][chc] - prefa[i-1][chc];
                else
                    pa.erase(chc);

            // print(i, l, r, mid, pa, pb);
            print("\n\nBefore: ");
            print(i, l, r, mid, pa);
            print(pb);
            bool valid = 1, found = 1;
            for (auto &[chb, freqb] : pb) {
                if (pa[chb] >= freqb) {
                    pa[chb] = 0;
                    freqb = 0;
                }
            }
            print("After: ");
            print(i, l, r, mid, pa);
            print(pb);

            int charsleft = 0, freqleft = 0;
            for (auto &[chb, freqb] : pb) {
                if (freqb) {
                    freqleft = freqb-pa[chb];
                    int mn = 1e7;
                    char chhhh = -1;
                    for (auto &[cha, freqa] : pa) {
                        if (freqa < mn && freqa >= freqleft) {
                            mn = freqa;
                            chhhh = cha;
                        }
                    }
                    if (chhhh != -1) {
                        print(chhhh);
                        pa[chhhh] = 0;
                    } else valid = 0;
                }
            }
            print(freqleft);
            print(valid, found);
            if (valid && found) {
                res = mid;
                r = mid-1;
            } else l = mid+1;
            pb = tpb;
        }
        cout << res << ' ';
    }
}