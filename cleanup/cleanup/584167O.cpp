#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace __gnu_pbds;
using namespace std;
#define sp << ' '
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define MOD 1000000007ll
#define b_rev boost::adaptors::reverse
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
#define vv(type) vector<vector<type>>
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define nl <<'\n'
template<class T> using ordered_set = tree<T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using min_queue = priority_queue<T, vector<T>, greater<>>;

// Pair addition
template<typename T, typename U, typename V, typename W>
auto operator+(const std::pair<T, U> &l, const std::pair<V, W> &r)
-> std::pair<decltype(l.first + r.first), decltype(l.second + r.second)> {
    return {l.first + r.first, l.second + r.second};
}

template<typename T>
T getValue() {
    T value;
    std::cin >> value;
    return value;
}

void printVec(vector<int> v) {
    for (const auto &i: v) { cout << i sp; }
    cout nl;
}

void printVec(vector<ll> v) {
    for (const auto &i: v) { cout << i sp; }
    cout nl;
}

void printVec(vector<vi> v) {
    for (const auto &item: v)printVec(item);
}

void printVec(vector<vector<ll>> v) {
    for (const auto &item: v)printVec(item);
}

void printPair(pair<ll, ll> x) { cout << x.first sp << x.second nl; }

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

short int sign(ll x) {
    if (x < 0) return -1;
    else if (x > 0) return 1;
    else return 0;
}

void solve();

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

void solve() {
    int n, a, b;
    cin >> a >> b >> n;
    int pa = 0, pb = 0;
    while (1) {
        (pa += a)%=n;
        (pb += b)%=n;
        if (pa == pb){
            cout << pa + 1 nl;
            return;
        }
    }
}