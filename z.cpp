#include <bits/stdc++.h>
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
    #define print(...) 69
    #define printarr(...) 69
#endif
using namespace std;
#define ll long long

void Rmdn() {
    ll l , r; cin >> l >> r;
    int ans = 0;
    for (int i = r; i > l; --i) {
        for (int j = i - 1; j >= l; --j) {
            ans = max(gcd(i , j) , ans);
            if(ans == i / 2)
                return void(cout << ans << '\n');
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // ll tc = 1;
    // cin >> tc;
    // for (int test = 1; test <= tc; ++test) {
    //     Rmdn();
    // }
    int n = 1e1+1;
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int mx = -1;
            for (int a = i; a <= j; a++) {
                for (int b = a+1; b <= j; b++) {
                    mx = max(mx, gcd(a,b));
                }
            }
            print(i, j, mx);
        }
    }
    return 0;
}