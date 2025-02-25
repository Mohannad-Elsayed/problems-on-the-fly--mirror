#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

istream &operator>>(istream &is,__int128_t &v) {
    string s;
    is>>s;
    v=0;
    for(auto &it:s) if(isdigit(it)) v=v*10+it-'0';
    if(s[0]=='-') v*=-1;
    return is;
}

#ifndef INT128_T_OSTREAM_OVERLOAD
#define INT128_T_OSTREAM_OVERLOAD
ostream &operator<<(ostream &os,const __int128_t &v) {
    if(v==0) return (os<<"0");
    __int128_t num=v;
    if(v<0) os<<'-',num=-num;
    string s;
    for(;num>0;num/=10) s.push_back((char)(num%10)+'0');
    reverse(all(s));
    return (os<<s);
}
#endif

template<typename T>
class rational {
private:
    int ctz_u128(__uint128_t u) {
        uint64_t lo = u, hi = u >> 64;
        int retval[3] = {
            __builtin_ctzll(lo),
            64 + __builtin_ctzll(hi),
            128
        };
        int idx = !lo + ((!hi) & (!lo));
        return retval[idx];
    }

    T hybrid_binary_gcd(T u, T v) {
        if (u < v) { swap(u, v); }
        if (v == 0) { return u; }
        u %= v;
        if (u == 0) { return v; }
        auto zu = ctz_u128(u);
        auto zv = ctz_u128(v);
        auto shift = min(zu, zv);
        u >>= zu;
        v >>= zv;
        do {
            T u_minus_v = u - v;
            if (u > v) { u = v, v = u_minus_v; }
            else {v = v - u; }
            v >>= ctz_u128(u_minus_v);
        } while (v != 0);
        return u << shift;
    }

    T neu, den;
    void reduce() {
        T g = hybrid_binary_gcd(neu, den);
        neu /= g;
        den /= g;
        if (den < 0) {
            neu = -neu;
            den = -den;
        }
    }

public:
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

void solve(){
    __int128_t r1, r2, p1, p2 = -1, l = 0, r = 1e18, m;
    cin >> r1 >> r2 >> p1;
    rational<__int128_t> old_profit(p1, r1*r1), new_profit;
    while(l<=r){
        m = (l+r)/2;
        new_profit = rational((10 * m),(r2 * r2));
        print(m, old_profit, new_profit);
        // print(old_profit.neu, old_profit.den);
        // print(new_profit.neu, new_profit.den);
        if (old_profit <= new_profit){
            r = m-1;
            p2 = 10 * m;
        } else l = m+1;
    }
    kill(p2);
}