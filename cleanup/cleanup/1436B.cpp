#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << x, 0;
#define killn(x) return cout << x << '\n', 0;

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #pragma GCC optimize("O3,unroll-loops,Ofast")
    // #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    pre(); 
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
vector<bool> sieve(int(1e5+10), true);
set<int> primes;
int pre(){
    for (ll i = 2; i*i <= int(1e5+10); i++)
        if (sieve[i])
            for (ll j = i*i; j < int(1e5+10); j += i)
                sieve[j] = false;
    for (int i = 2; i<int(1e5+10); i++)
        if (sieve[i])
            primes.insert(i);
    //________________________
    return 0;
}
int solve(){
    int n; cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 1));
    auto it = primes.upper_bound(n);
    for (; sieve[*it - n + 1]; it++);
    int x = *it - n + 1;
    for (int i = 0; i<n-1; i++){
        mat[i][n-1] = x;
        mat[n-1][i] = x;
    }
    it = primes.upper_bound((n-1) * x);
    for (; sieve[*it - (n-1) * x]; it++);
    mat.back().back() = *it - (n-1) * x;
    // print(mat);
    for (auto x : mat){
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
    //________________________
    return 0;
}