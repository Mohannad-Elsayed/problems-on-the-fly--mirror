#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define print(...) 69
//     #define printarr(...) 69
// #endif
#define sp ' '
#define loop(i, start, end) for (int i = start; i < end; i++)
#define ys cout << "YES"<<nl;
#define ns cout << "NO"<<nl;
#define ll long long
#define vint(v, n) vector<int>v(n)
#define allin(v) for(auto &i : v)cin>>i
#define nl '\n'
#define kill(x) return void(cout << (x) <<nl);
#define pli pair<ll, int> pli;
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define  mii map<int,int>
int dx[] = {-1, 1, 0, 0,-1,1,-1,1};
int dy[] = {0, 0, -1, 1,1,-1,-1,1};
const int mod=1e9+7;
bool is_prime(ll n)
{
    if(n==1||n==0)return 0;
    else if(n==2)return 1;
    else if(n%2==0)return 0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
void solve() {
    ll n, k; cin >> n >> k;
    string s = to_string(n);
    if (s.size() * k < 18) {
        string x;
        for (int i = 0; i < k; ++i) x += s;
        ll num = stoll(x);
        if (is_prime(num)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if (k == 1 && is_prime(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin.exceptions(cin.failbit);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    cin >> t;
   //t = 1;
    while (t--) {
        solve();
    }
    return 0;
}