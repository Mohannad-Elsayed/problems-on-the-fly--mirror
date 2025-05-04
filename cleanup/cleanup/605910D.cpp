#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
//#define int ll


void pre() {
}


struct node {
    int x, c, v;
};

void A3OOOO() {
    int n;
    cin >> n;

    vector<node> a(n);
    vector<vector<int>> val(1001, vector<int>(1001, 0));
    for(auto &[x, c, v] : a) {
        cin >> x >> c >> v;
        val[x][c] = v;
    }

    vector<vector<ll>>dp(1001, vector<ll>(1001, -1ll));

    function<ll(int,int)> solve = [&](int i, int t) {
        if(t == 1001)
            return 0ll;

        auto &ret = dp[i][t];
        if(~ret)
            return ret;

        ret = 0;
        if(i > 1)
            ret = max(ret, solve(i - 1, t + 1));
        if(i < 1000)
            ret = max(ret, solve(i + 1, t + 1));
        ret = max(ret, solve(i, t + 1));

        ret += val[i][t];
        return ret;
    };

    ll ans = 0;

    for(int i = 1; i <= 1000; i++) {
        ans = max(ans, solve(i, 1));
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("collector.in", "r", stdin);
    int tc = 1;
    pre();
    cin >> tc;
    while (tc--)A3OOOO();
    return 0;
}