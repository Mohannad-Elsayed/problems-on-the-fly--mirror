// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
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
int rnglr(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
void solve();
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

template<typename T>
class rational {
private:
    void reduce() {
        T g = gcd(neu, den);
        neu /= g;
        den /= g;
        if (den < 0) {
            neu = -neu;
            den = -den;
        }
    }

public:
    T neu, den;
    rational() : neu(0), den(1) {}
    rational(T n) : neu(n), den(1) {}
    rational(T n, T d) : neu(n), den(d) { reduce(); }
    rational& operator+=(const rational& r) {
        neu = neu * r.den + r.neu * den;
        den = den * r.den;
        reduce();
        return *this;
    }
    rational operator+(const rational& r) const {
        rational temp = *this;
        temp += r;
        return temp;
    }
    rational& operator-=(const rational& r) {
        neu = neu * r.den - r.neu * den;
        den = den * r.den;
        reduce();
        return *this;
    }
    rational operator-(const rational& r) const {
        rational temp = *this;
        temp -= r;
        return temp;
    }
    rational& operator*=(const rational& r) {
        neu *= r.neu;
        den *= r.den;
        reduce();
        return *this;
    }
    rational operator*(const rational& r) const {
        rational temp = *this;
        temp *= r;
        return temp;
    }
    rational& operator/=(const rational& r) {
        neu *= r.den;
        den *= r.neu;
        reduce();
        return *this;
    }
    rational operator/(const rational& r) const {
        rational temp = *this;
        temp /= r;
        return temp;
    }
    rational operator%(const rational& r) const {
        rational d = *this / r;
        T ip = d.neu / d.den;
        if(d.neu < 0 && d.neu % d.den != 0) ip--;
        return *this - rational(ip, 1) * r;
    }
    std::pair<T, rational> mod() const {
        T ip = neu / den;
        rational frac(neu - ip * den, den);
        return {ip, frac};
    }
    rational abs() const {
        return rational(neu < 0 ? -neu : neu, den < 0 ? -den : den);
    }
    rational& operator+=(const T& n) {
        neu += n * den;
        return *this;
    }
    rational operator+(const T& n) const {
        rational temp = *this;
        temp += n;
        return temp;
    }
    rational& operator-=(const T& n) {
        neu -= n * den;
        return *this;
    }
    rational operator-(const T& n) const {
        rational temp = *this;
        temp -= n;
        return temp;
    }
    rational& operator++() {
        *this += 1;
        return *this;
    }
    rational operator++(int) {
        rational temp = *this;
        ++(*this);
        return temp;
    }
    rational& operator--() {
        *this -= 1;
        return *this;
    }
    rational operator--(int) {
        rational temp = *this;
        --(*this);
        return temp;
    }
    rational operator+() const {
        return *this;
    }
    rational operator-() const {
        return rational(-neu, den);
    }
    bool operator==(const rational& r) const {
        return neu == r.neu && den == r.den;
    }
    bool operator!=(const rational& r) const {
        return !(*this == r);
    }
    bool operator<(const rational& r) const {
        return neu * r.den < den * r.neu;
    }
    bool operator<=(const rational& r) const {
        return neu * r.den <= den * r.neu;
    }
    bool operator>(const rational& r) const {
        return neu * r.den > den * r.neu;
    }
    bool operator>=(const rational& r) const {
        return neu * r.den >= den * r.neu;
    }
    friend std::ostream& operator<<(std::ostream& os, const rational& r) {
        os << r.neu << '/' << r.den;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, rational& r) {
        is >> r.neu >> r.den;
        r.reduce();
        return is;
    }
};
#define int ll
int sumoddrange(int l, int r) {
    return (r+1)/2 * (r+1)/2 - (l/2) * (l/2);
}
void solve() {
    map<int, int> mp;
    int n, k; cin >> n >> k;
    int p = 1ll<<k;
    vector<rational<int>> vr(n+1);
    for (int i = 1; i<=n; i++) {
        vr[i] = rational<int>(i, p);
    }
    int ans = 0;
    // each(r, vr)
    //     cout << r << '\n';
    each(r, vr) 
        ans += r.neu, mp[r.neu]++;
    cout << ans;
    print(mp);
    // print(sumoddrange(7, 9));
}