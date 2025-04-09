template<class info = int64_t>
class segment_tree {
    struct node {
        node *l, *r;
        info v;
        explicit node() : l(nullptr), r(nullptr), v(defaultVal) { }
        void create() {
            if(!l) l = new node(), r = new node();
        }
    } *root;
    int size;
    static info defaultVal;

    template<class U>
    void build(node *x, int lx, int rx, U &arr) {
        if(lx == rx) return void(x->v = arr[lx]);
        x->create();
        int m = (lx + rx) >> 1;
        build(x->l, lx, m, arr);
        build(x->r, m + 1, rx, arr);
        x->v = x->l->v + x->r->v;
    }

    info get(node *x, int lx, int rx, int l, int r) {
        if(lx != rx) x->create();
        if(lx > r || l > rx) return defaultVal;
        if(lx >= l && rx <= r) return x->v;
        int m = (lx + rx) >> 1;
        return get(x->l, lx, m, l, r) + get(x->r, m + 1, rx, l, r);
    }

    void set(node *x, int lx, int rx, int i, info val) {
        if(lx != rx) x->create();
        if (i < lx || i > rx) return;
        if(lx == rx) return void(x->v = val);
        int m = (lx + rx) >> 1;
        set(x->l, lx, m, i, val), set(x->r, m + 1, rx, i, val);
        x->v = x->l->v + x->r->v;
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
    void set(int i, info v) { // 0-based
        set(root, 0, size, i, v);
    }
    info get(int l, int r) { // 0-based, [l, r]
        return get(root, 0, size, l, r);
    }
};

struct info {
    int64_t sum, oring, anding, ggcd;
    info(int64_t x) {
        sum = oring = anding = ggcd = x;
    }
    info() { // default value
        sum = oring = ggcd = 0;
        anding = ~0;
    }
    friend info operator+(const info &l, const info &r) {
        info ret;
        ret.sum = l.sum+r.sum;
        ret.ggcd = gcd(l.ggcd, r.ggcd);
        ret.anding = l.anding & r.anding;
        ret.oring = l.oring | r.oring;
        return ret;
    }
};
template<> info segment_tree<info>::defaultVal = info();
