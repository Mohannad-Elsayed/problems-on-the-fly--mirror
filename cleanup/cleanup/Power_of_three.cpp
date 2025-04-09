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
#define ONLINE_JUDGE
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
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}
bool isPrime(int n){
    for (ll i = 2; i*i <= n; i++)
        if (n%i==0)
            return false;
    return true;
}
int solve(){
    string s; 
    cin >> s;
    if (s == "1")
        kill(0);
    
    ll n = s.size(), mp1 = 0, mp2 = 0, mp3 = 0, p1 = 1000000009, p2 = 123456803, p3 = 1000000007, pow_3m1 = 1, pow_3m2 = 1, pow_3m3 = 1;
    // for (ll i = 1e9+8; mp1 < 4; i++){
    //     if (isPrime(i))
    //         cout << i << '\n', mp1++;
    // }
    
    for (int i = 0; i < n; i++){
        s[i] -= '0';
        mp1 = mp1 * 10 + (s[i]);
        while (mp1 > p1)
            mp1 -= p1;

        mp2 = mp2 * 10 + (s[i]);
        while (mp2 > p2)
            mp2 -= p2;

        mp3 = mp3 * 10 + (s[i]);
        while (mp3 > p3)
            mp3 -= p3;
    }
    print(mp1, mp2, mp3);
    for (int i = 1; i < 1e3; i++){
        pow_3m1 *= 3;
        while (pow_3m1 > p1)
            pow_3m1 -= p1;
        pow_3m2 *= 3;
        while (pow_3m2 > p2)
            pow_3m2 -= p2;
        pow_3m3 *= 3;
        while (pow_3m3 > p3)
            pow_3m3 -= p3;
        print(i, pow_3m1, pow_3m2, pow_3m3);
        if (pow_3m1 == mp1 && pow_3m2 == mp2 && pow_3m3 == mp3)
            kill(i);
    }
    kill(-1);
    //________________________
    return 0;
}