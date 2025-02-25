// #define ONLINE_JUDGE
#include "bits/stdc++.h"
#include <omp.h> // Include OpenMP

using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

#pragma region fast_is_prime
const int MAXN = 200010;
template<int N>
struct Sieve {
    bool is_prime[N];
    constexpr Sieve() : is_prime() {
        for (int i = 2; i < N; i++) {
            is_prime[i] = true;
        }
        for (int i = 2; i < N; i++) if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
};
template<Sieve<MAXN> s>
struct SieveWrapper {
    static bool get(int n) {
        return s.is_prime[n];
    }
};
bool fast_is_prime(int n) {
    return SieveWrapper<Sieve<MAXN>{}>::get(n);
}
#pragma endregion fast_is_prime

struct ans1{
    ll cnt, l, r;
    vector<ll> v;

    ans1(ll a, ll b, ll c, vector<ll> _v) : cnt(a), l(b), r(c), v(_v){}
    
    friend string to_string(ans1 a) {
        stringstream ss;
        ss << "cnt: " << a.cnt << ", " << a.l << ' ' << a.r << '\n';
        each(i, a.v)
            ss << i << ' ';
        return ss.str();
    }
};
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif

void solve(){
    ll n; 
    cin >> n;
    ll ans = 0;
    // vector<ans1> answers;

    // Parallelize the outer loop using OpenMP
    #pragma omp parallel for schedule(dynamic,1) reduction(+:ans)
    for (ll i = 1; i <= n; i++) {
        // vector<ans1> local_answers; // Thread-local storage to avoid race conditions
        for (ll j = i + 1; j <= n; j++) {
            ll pnums = 0;
            // vector<ll> v;
            for (ll k = i; k <= j; k++) {
                if (fast_is_prime(k)) {
                    pnums++;
                    // v.push_back(k);
                }
            }
            if (fast_is_prime(pnums)) {
                ans++;
                // local_answers.push_back(ans1(pnums, i, j, v));
            }
        }
        
        //? Merge local answers into the main list in a thread-safe way
        // #pragma omp critical
        // answers.insert(answers.end(), all(local_answers));
    }
    
    // print(answers);
    kill(ans);
}
