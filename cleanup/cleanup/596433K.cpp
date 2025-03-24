// Hey there ... I love you :) <3
#include <bits/stdc++.h>
using namespace std;
#include "cleanup/debug.h"
auto solve(...) {
    int n, q;
    cin >> n >> q;


    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    vector<int64_t> prefix_sum(n + 1), prefix_xor(n + 1);

    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        prefix_xor[i] = prefix_xor[i - 1] ^ nums[i];
    }

    while ( q --> 0 ) {

        int l,r;cin >> l >> r;

        const int64_t sum  = prefix_sum[r] - prefix_sum[l - 1];
        const int64_t _xor = prefix_xor[r] ^ prefix_xor[l - 1];
        print(sum);
        print(_xor);
        const int64_t _and = sum & _xor;
        print(_and);

        cout << (_and & 1 ? "ODD" : "EVEN") << '\n';
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int tt = 1, tc = 1; // cin >> tt;
    while (tt-- > 0) solve(tc++);
}
