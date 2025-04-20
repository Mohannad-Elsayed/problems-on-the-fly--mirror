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


template<typename T>
class sparse {
private:
    int Log, n;
    //! change skip value
    T skip = -1; 
    vector<vector<T>> table;
    function<T(T, T)> merge;
    int is_overlap;

public:
    template<typename U>
    explicit sparse(vector<T> arr, U& f, int is_overlap = 0) 
        :is_overlap(is_overlap), n((int)arr.size()), merge(f), Log(__lg(arr.size()) + 1), table(Log, vector<T>(n)) {
        table[0] = arr;
        for (int l = 1; l < Log; l++) {
            for (int i = 0; i + (1 << (l - 1)) < n; i++) {
                table[l][i] = merge(table[l - 1][i], table[l - 1][i + (1 << (l - 1))]);
            }
        }
    }

    T query_overlap(int l, int r) { // [l, r], 0-based
        assert(l <= r);
        int len = __lg(r - l + 1);
        return merge(table[len][l], table[len][r - (1 << len) + 1]);
    }

    T query_non_overlap(int l, int r) { // [l, r], 0-based
        assert(l <= r);
        int sz = r - l + 1;
        T ret = skip;
        for (int i = 0; i < Log; i++) {
            if ((sz >> i) & 1) {
                ret = merge(ret, table[i][l]);
                l += (1 << i);
            }
        }
        return ret;
    }

    T query(int l, int r) {
        if (is_overlap) {
            return query_overlap(l, r);
        } else {
            return query_non_overlap(l, r);
        }
    }
};

void solve() {
    // sparse<int> s()
}

