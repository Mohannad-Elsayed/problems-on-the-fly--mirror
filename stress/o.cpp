#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
const ll MOD = (int)1e9 + 7;
int dx[] = {1, -1, 0, 0, };
int dy[] = {0, 0, 1, -1, };

void fileIO(){
// #ifndef ONLINE_JUDGE
//     freopen("../in.txt", "r", stdin);
//     freopen("../out.txt", "w", stdout);
// #endif
}

void solve() {
    int n, k, curr = 0, l = 0, r;
    cin >> n >> k;
    r = n - 1;
    vector<int> v(n), ans(n , -1);
   for(auto &i : v) cin >> i;

    sort(all(v));

    // if (k > (n - 1) / 2 || v.back() == v[0])
    //     return void(cout << -1 << endl);

    int idx = 0;
    for (int i = 0; i < n; i += 2) ans[i] = v[idx ++];
    for (int i = 1; i < n; i += 2) ans[i] = v[idx ++];

    curr = 0;
    for (int i = 1; i+1 < n; i++) {
        if (v[i] > v[i-1] && v[i] > v[i+1])
            curr++;
    }
    if (curr < k) {
        cout << -1;
        return;
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fileIO();
    
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {

//        cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}