#include <bits/stdc++.h>
#include "cleanup/debug.h"
using namespace std;
#define ll long long
const int N = 2e5 + 4;

void TC() {
    ll n, k , mx = 0 , el; 
    cin >> n >> k;
    vector<ll> vec(n);
    for(auto &i : vec)
        cin >> i;
    unordered_set<ll> ust;
    for (auto i : vec) {
        if (i <= n + 1)
            ust.insert(i);
    }
    // print(ust);
    while (ust.count(mx))
        mx++;
    ll l = 0, r = mx , ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        unordered_map<ll, ll> need , cur;
        for (int i = 0; i < mid; ++i)
            need[i] = 1;
        el = 0;
        int count = 0;
        for (auto i : vec) {
            if (i < mid) {
                cur[i]++;
                if (cur[i] == need[i])
                    count++;
            }
            if (count == mid) {
                el++;
                if (!cur.empty())
                    print(cur);
                cur.clear() , count = 0;
            }
        }
        if (el >= k)
            ans = mid , l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll tc = 1;
    // freopen("E4", "rt", stdin);
    cin >> tc;
    for (int test = 1; test <= tc; ++test) {
        TC();
    }
//    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
    return 0;
}