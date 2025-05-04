#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace __gnu_pbds;
using namespace std;

#define sp << ' '
#define cint (int)
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = vector<int>;
#define endl '\n'
#define sign(x) (x < 0 ? -1 : x > 0 ? 1 : 0)
typedef vector<ll> vll;
typedef array<int, 2> ii;
typedef vector<array<int, 2>> vii;
typedef array<ll, 2> pll;
#define nl <<'\n'
#define out(txt) {cout << txt << '\n'; return;}
#define MOD 1'000'000'007LL
#define EPS 1e-9
#define lsb(x) (x & -x)

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using min_queue = priority_queue<T, vector<T>, greater<>>;

template<typename Container>
void printVec(Container &v) {
    for (const auto &i: v) { cout << i << ' '; }
    cout nl;
}

//template<typename Container>
//void printVec(vector<Container> &v) {
//    for (const auto &item: v) printVec(item);
//}

void solve();

void precompute();

bool myPC = false;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    precompute();
    int t = 1;
     cin >> t;
    for (int i = 0; i < t; ++i) {
//        cout << "Case " << i + 1 << ": ";
        solve();
    }
}


void solve() {
    string s, t;
    cin >> s >> t;
    set<string> vis;
    queue<string> q;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    q.push(s);
    vis.insert(s);

    while (!q.empty()) {
        string x = q.front();
        q.pop();
        if (x == t) break;
        string cpy = x;
        cpy[0]++;
        if (cpy[0] > 'z') cpy[0] = 'a';
        sort(cpy.begin(), cpy.end());
        if (!vis.contains(cpy)) {
            vis.insert(cpy);
            q.push(cpy);
        }
    }
    cout << (vis.contains(t) ? "Yes\n" : "No\n");
}