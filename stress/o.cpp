#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define NF string::npos
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

/*//! Arithmetic sequence law
    sum = (n * (2*a + (n-1)*d))/2;
    n -> number of terms
    a -> first term
    d -> common difference
*/

using namespace std;

const int N = 2e5 + 5;
const int mod = 32768;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};



signed main()
{
    FAST;

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        deque <int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(allr(a));
        while(a.size() > 1)
        {
            int x = a[0] + a[1] - 1;
            a.pop_front();
            a.pop_front();
            a.push_front(x);
        }
        cout << a[0] << endl;
    }

    return 0;
}