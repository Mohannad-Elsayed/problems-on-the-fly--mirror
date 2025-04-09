#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define nl "\n"
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() {
    IO
    int t;cin >> t;
    while (t--) {
        ll n, ans = 0, mx = -1; cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            if(x > i && x > mx) {
                mx = x;
                // ans = max(ans, (ll)x - i);
                ans = x-i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}