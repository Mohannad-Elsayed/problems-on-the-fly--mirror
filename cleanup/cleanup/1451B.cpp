//#pragma GCC optimize("O3,unroll-loops,Ofast")
#include <bits/stdc++.h>
//#include "__int128.h"
using namespace std;
#define Trouble int $ = 1; for(  cin >> $  ;\
$--; solve())
//cout << '\n');
#define Shooter cin.tie(nullptr)->sync_with_stdio(false);\
cout.tie(nullptr);
#define forr($, $$, $$$)\
for(size_t $ = $$; $ < $$$; $++)
#define cin($$)\
for(auto &$ : $$) cin >> $
#define __sort($$)\
sort($$.begin(), $$.end())
#define __sort_g($$)\
sort($$.begin(), $$.end(), greater<>())
#define __reverse($$)\
reverse($$.begin(), $$.end())
#define __fixed($$)\
cout << fixed << setprecision($$);
#define __max_elem($$)\
max_element($$.begin(), $$.end())
#define __min_elem($$)\
min_element($$.begin(), $$.end())
#define F first
#define S second
#define int long long
const long long N = 1e6 + 5;

const long long __MOD = 1e18 + 7;

int __pow_MOD (int base, int exp, int mod = __MOD) {
    int res = 1LL; while (exp > 0LL) {
        if (exp % 2) res = (base % mod * res % mod) % mod;
        base = (base % mod * base % mod) % mod; exp /= 2;
    } return res;
}

int __pow (int base, int exp) {
    int res = 1LL; while (exp > 0LL) {
        if (exp % 2) res = (base  * res ) ;
        base = (base  * base ) ; exp /= 2;
    } return res;
}

int __ceil (int m, int a) { return (m + a - 1) / a; }

void solve();
signed main (void) {cin.tie(0)->sync_with_stdio(0); Trouble; }
//
//void solve() {
//    int n, q; cin >> n >> q;
//    string s; cin >> s;
//    int l, r;
//    while (q--) {
//        cin >> l >> r;
//        l--, r--;
//        bool found = false;
//        forr(i, 0, l)
//            if (s[i] == s[l]) {
//                found = true;
//                break;
//            }
//
//        if (!found) {
//            if (r != n - 1)
//            forr(i, r + 1, n)
//                if (s[i] == s[r]) {
//                    found = true;
//                    break;
//                }
//        }
//        printf("%s\n", (found ? "YES": "NO"));
//    }
//}


void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        bool hasBefore = false;
        for (int i = 0; i < l; i++) {
            if (s[i] == s[l]) {
                hasBefore = true;
                break;
            }
        }
        bool hasAfter = false;
        for (int i = r + 1; i < n; i++) {
            if (s[i] == s[r]) {
                hasAfter = true;
                break;
            }
        }

        cout << (hasBefore || hasAfter ? "YES" : "NO");
        cout << '\n';

    }
}