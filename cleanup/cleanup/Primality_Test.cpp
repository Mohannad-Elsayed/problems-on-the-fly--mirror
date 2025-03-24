#define ONLINE_JUDGE
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
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
void solve();

bool isPrime(ll n) {
    if (n == 1)
        return false;
    
    char primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    char primesc = sizeof(primes) / sizeof(primes[0]);
    
    for (char i = 0; i<primesc; i++) {
        if (n == primes[i])
            return true;
        if (n % primes[i] == 0)
            return false;
    }
    
    char arr[] = {1, 7, 11, 13, 17, 19, 23, 29};
    char arrc = sizeof(arr)/sizeof(arr[0]);
    // 30k + 1, 30k + 7
    for (ll i = 30; i * i <= n; i += 30)
        for (char j = 0; j < arrc; j++)
            if (n % (i+arr[j]) == 0)
                return false;

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    ll n; cin >> n;
    string_view yes = "Yes", no = "No";
    if (isPrime(n))
        yes;
    else    
        no;
}