#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << (x), 0;
#define killn(x) return cout << (x) << '\n', 0;

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
    #define printarr(...)
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){

    //________________________
    return 0;
}
bool isPrime(long long n) {
  
    if (n <= 1)
        return false;

    if (n == 2  ||
        n == 3  || 
        n == 5  ||
        n == 7  ||
        n == 11 ||
        n == 13 ||
        n == 17 ||
        n == 19 ||
        n == 23 ||
        n == 29
    )
        return true;
        
    if (n % 2  == 0  ||
        n % 3  == 0  || 
        n % 5  == 0  ||
        n % 7  == 0  ||
        n % 11 == 0  ||
        n % 13 == 0  ||
        n % 17 == 0  ||
        n % 19 == 0  ||
        n % 23 == 0  ||
        n % 29 == 0
    )
        return false;
    
    // 30k + 1, 30k + 7
    for (long long i = 30; i * i <= n; i += 30)
        for (long long a : {1, 7, 11, 13, 17, 19, 23, 29})
            if (n%(i+a) == 0)
                return false;

    return true;
}
int solve(){
    
    //________________________
    return 0;
}