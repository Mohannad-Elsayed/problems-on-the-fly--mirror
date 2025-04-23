// بسم الله الرحمن الرحيم
/**
████████╗██████╗░░█████╗░██╗░░░██╗██████╗░██╗░░░░░███████╗  ██████╗██╗░░██╗░█████╗░░█████╗░████████╗███████╗██████╗░
╚══██╔══╝██╔══██╗██╔══██╗██║░░░██║██╔══██╗██║░░░░░██╔════╝ ██╔════╝██║░░██║██╔══██╗██╔══██╗╚══██╔══╝██╔════╝██╔══██╗
░░░██║░░░██████╔╝██║░░██║██║░░░██║██████╦╝██║░░░░░█████╗░ ░╚█████╗░███████║██║░░██║██║░░██║░░░██║░░░█████╗░░██████╔╝
░░░██║░░░██╔══██╗██║░░██║██║░░░██║██╔══██╗██║░░░░░██╔══╝░  ░╚═══██╗██╔══██║██║░░██║██║░░██║░░░██║░░░██╔══╝░░██╔══██╗
░░░██║░░░██║░░██║╚█████╔╝╚██████╔╝██████╦╝███████╗███████╗ ██████╔╝██║░░██║╚█████╔╝╚█████╔╝░░░██║░░░███████╗██║░░██║
░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░╚═════╝░╚═════╝░╚══════╝╚══════╝ ╚═════╝░╚═╝░░╚═╝░╚════╝░░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝
**/
// Authored by Galal.
//#pragma GCC optimize("O2,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
#define forr(i, st, end) for (int i = st; i < end; i++)
#define cout(v, format) for (auto &i: v) cout << i << format
#define cin(v) for (auto &i: v) cin >> i
#define int long long
int __MOD = 1e9+7;
#define __fixed(d) cout << fixed << setprecision(d)
int __ceil (int m, int a) { return (m + a - 1) / a; }
bool is_sqrt (int x) { int root = sqrt(x); return root * root == x; }
template <typename T1, typename T2, typename T3>
class Triple {
public:
    T1 first; T2 second; T3 third; Triple() : first(), second(), third() {}
    Triple(T1 f, T2 s, T3 t) : first(f), second(s), third(t) {}
};
int __pow (int base, int exp, int mod = __MOD) {
    int res = 1LL;
    while (exp > 0LL) {
        if (exp % 2) res = (base % mod * res % mod) % mod;
        base = (base % mod * base % mod) % mod; exp /= 2;
    } return res;
}

vector<int> sieve (int n) {
    vector<bool> comp(n); vector<int> primes;
    comp[0] = comp[1] = true;
    for (int i=2; i*i <= n; i++) {
        if (not comp[i]) {
            for (int j=i*i; j<comp.size(); j+=i)
                comp[j] = true;
        }
    } forr (i, 0, n) if (not comp[i]) primes.push_back(i);
    return primes;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 or n == 3) return true;
    if (n % 2 == 0 or n % 3 == 0) return false;
    for (int i = 5; i * 1LL * i <= n; i += 6) {
        if (n % i == 0 or n % (i + 2) == 0)
            return false;
    }
    return true;
}


inline void solve();
//void precomute ();

/*################################# Main Function ##########################*/

signed main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}

/* ############################ Start Solve ####################################*/

// وما توفيقى الا بالله

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin (a);

    vector<int> freq(1e6 + 5, 0);
    int l = 0, r = 0;
    int cost = 0, ans = 0;


    for (int r = 0, l = 0; r < n; r++) {
        while(l < r && cost <= k) {
            if (!freq[a[l]]) {
                cost += a[l];
            }
            freq[a[l]]++;
            l++;
        }
        cout << "cost : " << cost << '\n';
        ans = max(ans, r-l);

    }
    // while (r < n) {
    //     if (freq [a[r]] == 0) {
    //         if (cost + a[r] <= k) {
    //             cost += a[r];
    //         }
    //         else {
    //             while (cost + a[r] > k and l < r) {
    //                 freq [a[l]] --;
    //                 if (freq[a[l]] == 0) cost -= a[l];
    //                 l ++;
    //             }
    //         }
    //     }
    //     ans = max (ans, r - l + 1);
    //     freq [a[r]] ++;
    //     r ++;
    // }

    cout << ans;
}