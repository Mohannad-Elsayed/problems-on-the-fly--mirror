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
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<31);
void solve();

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


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // freopen("35", "rt", stdin);
    sieve((int)1e5);
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int MOD = (int) 1e13 + 7;
ll fp(ll b, ll n) {
    b %= MOD;
    ll s = 1;
    while (n) {
        if (n & 1) s = s * b % MOD;
        b = b * b % MOD;
        n /= 2;
    }
    return s;
}
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll divide(ll a, ll b) { return mul(a, fp(b, MOD - 2)); }

void solve() {
    int n, k, cnt; cin >> n >> k;
    map<int, vector<int>> ps; // unique primes in all numbers & their frequency
    while(n--) {
        int k; 
        cin >> k;
        each(p, primes) {
            cnt = 0;
            if (1ll * p * p > k)
                break;
            while(k % p == 0)
                k /= p, cnt++;
            ps[p].push_back(cnt);
        }
        if (k != 1)
            ps[k].push_back(1);
    }
    // print(ps);
    ll lccm = 1;
    each(p, ps) {
        print(p.second.size(), k);
        if (p.second.size() < k)
            continue;
        sort(rall(p.second));
        lccm = mul(lccm, fp(p.first, p.second[k-1]));
    }
    cout << lccm;
}