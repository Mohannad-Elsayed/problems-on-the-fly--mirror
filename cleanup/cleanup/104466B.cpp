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
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
void c(bool f) {
    cout << (f ? "possible" : "impossible");
    exit(0);
}
class DSU {
    private:
    int N = 0, numSets;
    vector<int> root;
    vector<int> sze;
    bool is_initialized(){
        return N;
    }
    void make_set(int u){
        assert(is_initialized());
        root[u] = u;
        sze[u] = 1;
    }
    public:
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int _n){
        N = _n + 100;
        root.resize(N);
        sze.resize(N);
        numSets = _n;
        for (int i = 0; i<N; i++)
            make_set(i);
    }
    int find_set(int u){
        assert(is_initialized());
        while (u != root[u]) 
            u = root[u] = root[root[u]];
        return u;
    }
    bool union_set(int u, int v){
        assert(is_initialized());
        u = find_set(u), 
        v = find_set(v);
        if (u != v){
            if (sze[u] > sze[v])
                swap(u, v); // u is smaller, then root[u] = v
            root[u] = v; // rep of the smaller is the bigger representative 
            sze[v] += sze[u]; // size of the bigger is increased
            return --numSets;
        }
        return false;
    }
    bool same_set(int u, int v){
        assert(is_initialized());
        return find_set(u) == find_set(v);
    }
    int size_set(int u){
        return sze[find_set(u)];
    }
    int size(){
        return numSets;
    }
};
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
void solve() {
    int n; cin >> n;
    DSU d(n);
    vector<pair<int, int>> vp(n);
    each(i, vp)
        cin >> i.first >> i.second;
    map<rational<int>, vector<int>> mp;
    
    for (int i = 0; i<n; i++) {
        for (int j = i+1; j<n; j++) {
            rational<int> s(vp[i].second-vp[j].second, vp[i].first-vp[j].first);
            print(s);
            print(i, j);
            mp[s].emplace_back(i);
            mp[s].emplace_back(j);
        }
    }
    print(mp);
    each(vv, mp)
        each(i, vv.second)
            d.union_set(i, vv.second.front());
    print(d.size());
}