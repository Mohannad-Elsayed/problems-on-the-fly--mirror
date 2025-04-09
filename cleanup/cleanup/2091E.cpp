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
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<31);
void solve();

template <typename T>
struct SafeVector : public vector<T> {
    using vector<T>::vector; // Inherit constructors

    T& operator[](size_t index) {
        return this->at(index); // Replace [] with .at()
    }

    const T& operator[](size_t index) const {
        return this->at(index); // Replace [] with .at() for const objects
    }
};

vector<int> smallest_factor;
vector<int> smallest_factor_tmp;
vector<bool> prime;
vector<int> saved;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    smallest_factor_tmp.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            for (int64_t i = int64_t(p)*2; i <= maximum; i += p) {
                // if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                    smallest_factor_tmp[i]++;
                // }
            }
        }
}

// int factorlg(int _n){
//     unordered_map<int, int> fac;
//     while(smallest_factor[_n]){
//         fac[smallest_factor[_n]]++;
//         _n /= smallest_factor[_n];
//     }
//     return (int) fac.size();
// }

// int stress(int _n) {
//     int n = _n;
//     int cnt = 0; 
//     for (int a = 1; a <= n; a++) {
//         for (int b = a+1; b <= n; b++) {
//             if (prime[lcm(a, b) / gcd(a, b)]) {
//                 // print(a, b);
//                 cnt++;
//             }
//         }
//     }
//     // print(cnt);
//     return cnt;
// }


void pre() {
    int N = (int) 1e7 + 10;
    sieve(N);
    saved = vector<int>(N);
    int cntprime = 0, nonprimeacc = 0, cc;
    for (int i = 2; i<N; i++) {
        if (prime[i]) {
            cntprime++;
            saved[i] = cntprime + nonprimeacc;
        } else {
            // cc = factorlg(i);
            cc = smallest_factor_tmp[i];
            nonprimeacc += cc;
            saved[i] = saved[i-1] + cc;
        }
    }
    
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // stress();
    // exit(0);
    pre();
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
void solve() {
    // for (int i = 0; i<100; i++)
    //     cout << (smallest_factor_tmp[i]) << ' ';
    int n; cin >> n;
    cout << saved[n];
    
}