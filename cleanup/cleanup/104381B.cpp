// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<30);
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

int dx[8] = {2, 1, -1, -2, -2, -1,  1,  2};
int dy[8] = {1, 2,  2,  1, -1, -2, -2, -1}; // knight
#define int ll
void solve() {
    int x, x2, y, y2;
    cin >> x >> y >> x2 >> y2;
    x += 1e9, y += 1e9, x2 += 1e9, y2 += 1e9;
    if (x == x2 && y == y2)
        kill(2); // ?

    auto diag = [&]() -> bool {
        return abs(y-y2) == abs(x-x2);
    };

    auto colo = [&]() -> bool {
        return (x+y)%2 == (x2+y2)%2;
    };

    if (colo()) {
        if (diag())
            kill(1);
        kill(2);
    }

    int ans1 = 10, ans2 = 10;
    for (int i = 0; i<8; i++) {
        if (x + dx[i] == x2 && y + dy[i] == y2) {
            chmin(ans1, 1ll);
        }
        for (int j = 0; j<8; j++) {
            int nx = x + dx[i] + dx[j],
                ny = y + dy[i] + dy[j];
            if (nx == x2 && ny == y2)
                chmin(ans1, 2ll);
        }
    }

    for (int i = 0; i<8; i++)
        if (abs(x + dx[i] - x2) == abs(y + dy[i] - y2))
            chmin(ans2, 2ll);

    kill(min({3ll, ans1, ans2}));

}