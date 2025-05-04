#pragma region Defines

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef long double ld;
typedef unsigned long long ull;
#define el '\n'
#define F first
#define S second
#define I00 0x3f3f3f3f
#define int128 __int128
#define PI 3.141592653590
#define L00 0x3f3f3f3f3f3f3f3f
#define NL00 -0x3f3f3f3f3f3f3f3f
#define yes cout<<"YES\n";return;
#define no cout<<"NO\n";return;
#define all(a)  a.begin(), a.end()
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define Num_of_Digits(n) ((int(log10(n)) + 1))
#define Lion_Heart ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void file() {
    freopen("strings.in", "r", stdin);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#pragma endregion

int const N = 2e5 + 5, M = 2 * N + 9, SQRT = 1e6 + 10, mod = 1e9 + 7;

//------------start solve-------------------
void solve() {
    string a, b;
    cin >> a >> b;
    int n = size(a), m = size(b);
    a = "#" + a; // one-based
    b = "#" + b + "#";
    vector<vector<int>> pref(n + 5, vector<int>(28, 0));
    vector<int> suff(m + 2, -1);
    for (int i = 1; i <= n; ++i) {
        ++pref[i][a[i] - 'a'];
    }
    for (int i = 1; i <= n + 2; ++i) {
        for (int j = 0; j <= 26; ++j) {
            pref[i][j] += pref[i - 1][j];
        }
    }
    int p1 = n, p2 = m;
    while (p1 > 0 and p2 > 0) {
        if (a[p1] == b[p2]) {
            suff[p2--] = p1;
        }
        --p1;
    }

    if (p2 > 0)
        return void(cout << -1 << el);

    int mx = 0, mx1 = 0, mx2 = 0;
    suff[m + 1] = suff[m];
    suff[0] = 0;

    // handle first char
    int mtch1 = suff[2];
    int rep1 = pref[mtch1 - 1][b[1] - 'a'];
    mx = max(mx, rep1 - 1);
    // cout << "mx " << mx << '\n';
    // handle last char
    int mtch2 = suff[m + 1];
    int mtch3 = suff[m - 1];
    int rep2 = pref[mtch2][b[m] - 'a'] - pref[mtch3][b[m] - 'a'];
    mx = max(mx, rep2 - 1);
    // cout << "mx " << mx << '\n';

    // handle midddle chars
    for (int i = 2; i < m; ++i) {
        int matchAfter = suff[i + 1];
        int matchbefore = suff[i - 1];
        if (matchAfter == -1 or matchbefore == -1) {
            assert(false);
            continue;
        }
        int c = (b[i] - 'a');
    // int freq = pref[matchAfter][c] - pref[i][c];
        int rep = pref[matchAfter - 1][c] - pref[matchbefore][c];
        mx = max(mx, rep - 1);
    // cout << matchbefore << " " << matchAfter << " " << char(c + 'a') << " " << rep - 1 << el;

    }
    cout << m + mx << el;
}

int main() {
    // file();
    Lion_Heart
    cout << fixed << setprecision(15);
    int tc = 1;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        solve();
    }
    return 0;
}
/**
 you can ^_^ (•‿•)
( إن الله وملائكته يصلون على النبي يا أيها الذين آمنوا صلوا عليه وسلموا تسليما )
**/