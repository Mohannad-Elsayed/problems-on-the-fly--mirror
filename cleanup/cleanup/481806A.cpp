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
#define each(x, v) for (auto &(x) : (v))
void solve();
int N = 1e6+2;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

ll power(ll a, ll n){
    ll ans = 1;
    while (n > 0){
        ll last = (n & 1);
        if (last) ans = ((ans ) * (a )) ;
        a = ((a ) * (a )) ;
        n = n >> 1;
    }
    return ans;
}

vector<ll> v(N+10);
ll sumdivs(ll n){
    ll sum = 1;
    map<int, int> pf;
    while(smallest_factor[n])
        pf[smallest_factor[n]]++, n /= smallest_factor[n];
    
    for (auto [x, y] : pf)
        sum *= (power(x, y+1)-1)/(x-1);
    return sum - n;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;

    sieve(N);
    // int n = 6;
    // while(smallest_factor[n])
    //     cout << smallest_factor[n] << ' ', n /= smallest_factor[n];
    // exit(0);

    for (int i = 1; i<=N; i++){
        v[i] = sumdivs(i);
    }
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int x; cin >> x;
    cout << v[x] << '\n';
    if (v[x] > x)   
        cout << "abundant";
    else if (v[x] < x)
        cout << "deficient";
    else 
        cout << "perfect";
}