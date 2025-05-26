// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
    #define print(...) ((void)0)
    #define printarr(...) ((void)0)
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
template<class T> T rnglr(T l, T r) {return uniform_int_distribution<T>(l, r)(rng);}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("area.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

string base11_digits = "AHIMOTUVWXY";
unordered_map<char, int> char_to_digit = {
    {'A', 0}, {'H', 1}, {'I', 2}, {'M', 3}, {'O', 4},
    {'T', 5}, {'U', 6}, {'V', 7}, {'W', 8}, {'X', 9}, {'Y', 10}
};

ll from_base11(const string& s) {
    ll res = 0;
    for (char c : s) {
        res = res * 11 + char_to_digit[c];
    }
    return res;
}

string to_base11(ll n) {
    if (n == 0) return string(1, base11_digits[0]);
    string res;
    while (n > 0) {
        res += base11_digits[n % 11];
        n /= 11;
    }
    reverse(res.begin(), res.end());
    return res;
}

// Adds two base 11 numbers represented as strings
string add_base11(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    int i = n - 1, j = m - 1, carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int d1 = (i >= 0) ? char_to_digit[a[i]] : 0;
        int d2 = (j >= 0) ? char_to_digit[b[j]] : 0;
        int sum = d1 + d2 + carry;
        res += base11_digits[sum % 11];
        carry = sum / 11;
        i--; j--;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    string s, ks; 
    int k; cin >> k >> s;
    ks = to_base11(k);
    string ans = add_base11(s, ks);
    for (int i = 0; i < ans.size() - s.size(); i++)
        ans[i] = base11_digits[base11_digits.find(ans[i])-1];
    print(ans);
    cout << ans;
}