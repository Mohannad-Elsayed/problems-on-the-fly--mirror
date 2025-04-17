#define ONLINE_JUDGE
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
    cout << fixed << setprecision(10);
    int tt = 1;
    // cin >> tt;
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
    friend string to_string(const rational& r) {
        return to_string(r.neu) + " / " + to_string(r.den);
    }
};

#define int ll
void solve() {
    int t0, t1, t2, x1, x2, y1, y2, mx = -1, ansx, ansy, left, right, mid, res;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if (t1 == t2) {
        cout << x1 << ' ' << x2;
        return;
    }
    if (t1 == t0) {
        cout << x1 << ' ' << 0;
        return;
    }
    if (t2 == t0) {
        cout << 0 << ' ' << x2;
        return;
    }
    // rational<int> t0t(t0), lstdiff(int(1e8));
    auto fun = [&](int a, int b) -> rational<int> {
        return rational<int>(((a*t1) + (b*t2)), (a+b));
    };
    auto fund = [&](long double a, long double b) -> long double {
        return ((long double)(a*t1) + (b*t2)) / (long double)(a+b);
    };

    // for (int i = 0; i <= x1; i++) {
    //     left = !i, right = x2;
    //     while(left <= right) {
    //         mid = left+right >> 1;
    //         if (fun(i, mid) >= t0t) {
    //             res = mid;
    //             right = mid-1;
    //         } else left = mid+1;
    //     }
    //     if (chmax(mx, i+res) && (fun(i, res) - t0t) <= lstdiff) {
    //         mx = i+res;
    //         ansx = i;
    //         ansy = res;
    //         lstdiff = (fun(i, res) - t0t);
    //     }
    // }
    // print(fun(ansx, ansy));
    // cout << ansx << ' ' << ansy;

    print(fund(110, 79));
    print(fund(76, 54));
    print(fund(38, 27));
    rational<int> smdiff(int(1e8));
    for (int i = x1; ~i; i--) {
        // i -> y1
        assert(t0 != t2);
        long double y2 = (long double)i * (t1-t0) / (t0-t2);
        print(i, y2);
        print(fund(i, y2));
        auto y2r = rational<int>(i * (t1-t0), (t0-t2));
        print(y2r);
        if (y2r.den == 1 && y2 >= 0 && (i > 0 || y2 > 0)) {
            cout << i << ' ' << (int)y2;
            return;
        }
        if (!i && !((y2r.neu+y2r.den-1)/y2r.den))
            continue;;
        auto ansy2 = fun(i, (y2r.neu+y2r.den-1)/y2r.den);
        print(ansy2);
        print((y2r.neu+y2r.den-1)/y2r.den);
        if (ansy2 < smdiff) {
            smdiff = ansy2;
            ansx = i;
            ansy = (y2r.neu+y2r.den-1)/y2r.den;
            print(ansx, ansy);
            print("\n");
        }
    }
    cout << ansx << ' ' << ansy;
}