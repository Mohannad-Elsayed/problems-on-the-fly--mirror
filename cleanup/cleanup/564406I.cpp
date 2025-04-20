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

#define int ll
template<class T = int64_t>
class lazySegment {
    struct node {
        node *l, *r;
        T v{}, E{};
        int idx{}; // store index of maximum
        explicit node() : l(nullptr), r(nullptr) { }
        void build() {
            if(!l) l = new node(), r = new node();
        }
    } *root;
    int size;
    
    inline static void merge(node *x) {
        if(x->l->v > x->r->v) {  // strictly greater: if equal, take right child
            x->v = x->l->v;
            x->idx = x->l->idx;
        } else {
            x->v = x->r->v;
            x->idx = x->r->idx;
        }
    }

    inline static void push(node *x, const int &lx, const int &rx) {
        if(x->E) {
            if(x->l) x->l->E += x->E;
            if(x->r) x->r->E += x->E;
            x->v -= x->E; // subtract instead of add
            x->E = 0;
        }
    }

    template<class U>
    void build(node *x, int lx, int rx, U &arr) {
        if(lx == rx) {
            x->v = arr[lx];
            x->idx = lx;
            return;
        }
        x->build();
        int m = (lx + rx) >> 1;
        build(x->l, lx, m, arr);
        build(x->r, m + 1, rx, arr);
        merge(x);
    }

    pair<T,int> get(node *x, int lx, int rx, int l, int r) {
        if(lx != rx) x->build();
        push(x, lx, rx);
        if(lx > r || l > rx) return {numeric_limits<T>::min(), -1};
        if(lx >= l && rx <= r) return {x->v, x->idx};
        int m = (lx + rx) >> 1;
        auto left = get(x->l, lx, m, l, r);
        auto right = get(x->r, m + 1, rx, l, r);
        if(left.first == right.first) {
            return right;
        }
        if(left.first > right.first) return left;
        return right;
    }

    void set(node *x, int lx, int rx, int i, T val) {
        if(lx != rx) x->build();
        push(x, lx, rx);
        if (i < lx || i > rx) return;
        if(lx == rx) {
            x->v = val;
            x->idx = lx;
            return;
        }
        int m = (lx + rx) >> 1;
        set(x->l, lx, m, i, val), set(x->r, m + 1, rx, i, val);
        merge(x);
    }

    void Range(node *x, int lx, int rx, int l, int r, T val) {
        if(lx != rx) x->build();
        push(x, lx, rx);
        if(lx > r || l > rx) return;
        if(lx >= l && rx <= r) {
            x->E = val;
            push(x, lx, rx);
            return;
        }
        int m = (lx + rx) >> 1;
        Range(x->l, lx, m, l, r, val), Range(x->r, m + 1, rx, l, r, val);
        merge(x);
    }

    void del(node *x) {
        if(x){
            del(x->l), del(x->r);
            delete x;
        }
    }
public: // 0-based
    explicit lazySegment(int n = 1000000000) : size(n), root(new node()) { }

    template<class U>
    explicit lazySegment(U &arr) : size(int(arr.size()) - 1), root(new node()) {
        build(root, 0, size, arr);
    }
    ~lazySegment(){
        del(root);
    }
    void set(int i, T v) {
        set(root, 0, size, i, v);
    }
    pair<T,int> get(int l, int r) {
        return get(root, 0, size, l, r);
    }
    void Range(int l, int r, T val) {
        Range(root, 0, size, l, r, val);
    }
};

int ninf = -1e10;
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    getv(v);
    lazySegment<int> lsg(v);
    for (int i = 0; i<n; i++) {
        auto p = lsg.get(0, n-1);
        cout << p.first << ' ';
        lsg.set(p.second, ninf);
        lsg.Range(p.second, n-1, 1);
    }
}