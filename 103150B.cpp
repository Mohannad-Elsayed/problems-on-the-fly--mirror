#include <bits/stdc++.h>
#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long
#define el '\n'
#define sp ' '
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define CEIL(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define posMod(a, m) ((a) % (m) + (m)) % (m)
#define ON(n, k) ((n) | (1LL << k))
#define OFF(n, k) ((~(1LL << k)) & (n))
#define isON(n, k) (((n) >> (k)) & 1LL)
#define FLIP(n, k) ((1LL << k) ^ n)
#define msb1(x) (63 - __builtin_clzll(x))
#define lsb1(x) (__builtin_ctzll(x))
#define msb0(x) (63 - __builtin_clzll(~x))
#define lsb0(x) (__builtin_ctzll(~x))
#define pb(x) push_back(x)
#define EPS 1e-9
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
using namespace std;

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}

void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 0; i < n; i++)
    {
        int cnt = 0, rem = 0;
        for (int j = 0; j + 1 < m; j++)
        {
            if (grid[i][j] == '>' && grid[i][j + 1] == '<')
                cnt++;
            else if (grid[i][j] == grid[i][j + 1])
                rem++;
        }

        ans += (cnt * (cnt + 1)) / 2 + (cnt ? rem : 0);
    }

    for (int j = 0; j < m; j++)
    {
        int cnt = 0, rem = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            if (grid[i][j] == 'v' && grid[i + 1][j] == '^')
                cnt++;
            else if (grid[i][j] == grid[i + 1][j])
                rem++;
        }
        ans += (cnt * (cnt + 1)) / 2 + (cnt ? rem : 0);
    }
    cout << ans << el;
}

signed main()
{
    FAST
#ifdef LOCAL
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //   cin >> t;
    while (t--)
        solve();
    return 0;
}