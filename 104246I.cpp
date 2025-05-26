#include <bits/stdc++.h>
// #include "cleanup/debug.h"
using namespace std;

void TC() {
    int l, r, k;
    cin >> l >> r >> k;

    auto cnt = [&](int x, int r) {
        return r / x;
    };

    int64_t ans = 0;
    for(int d = 1; d * d <= k; d++) {
        if(k % d == 0 && gcd(d, k / d) == 1) {
            int x = k / d;
            int y = d;
            int cx = r/x;

            // int tcy = cx;
            // while(tcy*y >= l)
            //     tcy--;
            // print(tcy);

            int bl = 0, br = cx, bmid, cy = cx;
            while(bl <= br) {
                bmid = bl+br >> 1;
                if (bmid * y >= l) {
                    br = bmid-1;
                } else {
                    cy = bmid;
                    bl = bmid+1;
                }
            }
            // print(cy);

            ans += max<int>(0, cx-cy);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int test = 1; test <= tc; ++test) {
        TC();
    }
//    cerr << clock() / 1000.0 << " Secs";
    return 0;
}