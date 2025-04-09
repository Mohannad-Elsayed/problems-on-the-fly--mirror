// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
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
uniform_int_distribution<> uid(1, 1ll<<30);
void solve();

template<class info = int64_t>
class segment_tree {
    static const info defaultVal = -1;
    info combine(info a, info b) {
        return a&b;
    }
    struct node {
        node *l, *r;
        info v;
        explicit node() : l(nullptr), r(nullptr), v(defaultVal) { }
        void create() {
            if(!l) l = new node(), r = new node();
        }
    } *root;
    int size;

    template<class U>
    void build(node *x, int lx, int rx, U &arr) {
        if(lx == rx) return void(x->v = arr[lx]);
        x->create();
        int m = (lx + rx) >> 1;
        build(x->l, lx, m, arr);
        build(x->r, m + 1, rx, arr);
        x->v = combine(x->l->v, x->r->v);
    }

    info query(node *x, int lx, int rx, int l, int r) {
        if(lx != rx) x->create();
        if(lx > r || l > rx) return defaultVal;
        if(lx >= l && rx <= r) return x->v;
        int m = (lx + rx) >> 1;
        return combine(query(x->l, lx, m, l, r), query(x->r, m + 1, rx, l, r));
    }

    void set(node *x, int lx, int rx, int i, info val) {
        if(lx != rx) x->create();
        if (i < lx || i > rx) return;
        if(lx == rx) return void(x->v = val);
        int m = (lx + rx) >> 1;
        set(x->l, lx, m, i, val), set(x->r, m + 1, rx, i, val);
        x->v = combine(x->l->v, x->r->v);
    }

    void del(node *x) {
        if(x){
            del(x->l), del(x->r);
            delete x;
        }
    }
public:
    explicit segment_tree(int n = 1'000'000'000) : size(n), root(new node()) { }

    template<class U>
    explicit segment_tree(U &arr) : size(int(arr.size()) - 1), root(new node()) {
        build(root, 0, size, arr);
    }
    ~segment_tree(){
        del(root);
    }
    void set(int i, info v) {
        set(root, 0, size, i, v);
    }
    info query(int l, int r) {
        return query(root, 0, size, l, r);
    }
};


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

void solve() {
    int n, q, a, lq, k; cin >> n;
    vector<int> v(n);
    getv(v);
    segment_tree<int> sprs(v);
    cin >> q;
    while (q--) {
        cin >> lq >> k;
        int l = --lq, r = n-1, m, ans = -1;
        while (l <= r) {
            m = (l+r)/2;
            if (sprs.query(lq, m) >= k) {
                l = ans = m+1;
            } else {
                r = m-1;
            }
        }
        cout << ans << ' ';
    }
}