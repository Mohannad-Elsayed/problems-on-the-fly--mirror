/*
 *          The Artist :
 *
                    ███████╗██╗ █████╗ ██████╗
                    ╚══███╔╝██║██╔══██╗██╔══██╗
                      ███╔╝ ██║███████║██║  ██║
                     ███╔╝  ██║██╔══██║██║  ██║
                    ███████╗██║██║  ██║██████╔╝
                    ╚══════╝╚═╝╚═╝  ╚═╝╚═════╝

            The Art : . . .
 * */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define nl <<'\n'
#define vll vector<ll>
#define vi vector<int>
#define pb(x) push_back(x)
#define dbg(x) cout<<#x<<" = "<<x<<nl
#define sp <<' '
#define get(n, t) get<n>(t)
#define geti(n, i, t) get<n>(t)=i
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define ll long long
#define int long long
#define see(v) for(auto &i : v)cin>>i
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define f first
#define ss second
#define pc(x) __builtin_ctz(x)
#define  no cout<<"NO" nl;
#define  yes cout<<"YES" nl;
#define pii pair<int , int>
#define vpii vector<pii>
//Orderd set
template<class T> using ordered_set = tree<T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;
//multi ordered set
template<class T> using multi_ordered_set = tree<T, null_type, less_equal<T>,
        rb_tree_tag, tree_order_statistics_node_update>;
double sTime;

void File() {
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
//     sTime = clock();
// #endif
}

void endFile() {
#ifndef ONLINE_JUDGE
    double eTime = clock();
    double TIME_TAKEN = double(eTime - sTime) / double(CLOCKS_PER_SEC);
    cout << "\n//Time taken = " << fixed << std::setprecision(5) << TIME_TAKEN << "ms\n";
#endif
}
/*
 * __builtin_clz(x): the number of zeros at the beginning of the number
 * __builtin_ctz(x): the number of zeros at the end of the number
 * __builtin_parity(x): the parity (even or odd) of the number of ones
 */
//##############################################################################################################
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char di[] = {'D', 'L', 'U', 'R'};

//const int N = 1e3 + 1;
//const ll mod = 1e9 + 7;

void solve() {
    int n; cin>>n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    int j = n-1;
    int ans = 0;
    int i = 0;
    while(j > i)
    {
        while(a[j]+a[i] <= (j+1) && i < j) i++;
        ans += j - i;

        j--;
    }

    cout<<ans nl;
}

signed main() {
    fastio
    File();
    int t = 1;
    cin >> t;
    int T = t;
    while (t--) {
        solve();
    }
    //endFile();

    return 0;
}