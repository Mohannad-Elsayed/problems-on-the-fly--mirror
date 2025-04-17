#include <bits/stdc++.h>
using namespace std;

#define Dattebayo() ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define all(v) ((v).begin()), ((v).end())
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ll long long
#define int long long
#define endl "\n"
#define pii pair <int,int>
///Where there's a will there's a way.
///Well, نـورت الكــود يـعـمـنـا

void solve() {
    int n, m, k; cin >> n >> m >> k;
    if(n%k == 0 || m%k == 0) {
        for(int i = 1; i <= n; i++) {
            int cnt = (i %k) + 1;
            for(int j = 1; j <= m; j++) {
                cout << cnt ++ << " ";
                if(cnt > k) cnt = 1;
            }
            cout << endl;
        }
    }
    else {
        int cnt = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << cnt ++ << " ";
                if(cnt > k) cnt = 1;
            }
            cout << endl;
        }
    }
}

void setIO() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main ()
{
    setIO();
    Dattebayo();

    int t = 1, i = 1;
    cin >> t;

    while (t --) {
        // cout << "Case " << i ++ << ": ";
        solve();
        // cout << endl;
    }

}