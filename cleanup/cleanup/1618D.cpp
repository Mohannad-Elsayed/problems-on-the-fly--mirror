/// Zengy MANGA
// #pragma GCC optimize("O3")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i, a, b)  for(int i = a; i < b; i++)
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define mp(x,y) make_pair(x,y)
#define popCnt(x) (__builtin_popcountll(x))

using ll = long long;
using ii = pair<int,int>;
using ull = unsigned long long;
using db = long double;

const int N = 1e6+5, LG = 18, MOD = 1e9 + 7;
const long double PI = acos(-1);

void doWork(){

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    f(i,0,n)    cin >> a[i];
    sort(all(a));
    vector<int> v;
    f(i,0,2*k) {
        v.pb(a.back());
        a.pop_back();
    }
    ll ans = accumulate(all(a), 0);
    map<int, int> mp;
    for(auto x : v)mp[x] += 1;
    for(auto it : mp)
    if(it.second >= k) {
        ans += it.second - k;
    }

    cout << ans << '\n';

}
int main() {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif

    int t = 1;
    cin >> t;
    while(t--) {
        doWork();
    }

	return 0;
}
