// Node* root = 0;
// update(root, 0, N-1, idx, val);
// query(root, 0, N-1, l, r);
struct Node {
    Node *l = 0, *r = 0;
    int val = 0;
};
void update(Node*& x, int lx, int rx, int i, int v) {
    if (!x) x = new Node();
    if (lx == rx) { x->val = v; return; }
    int m = (lx + rx) / 2;
    if (i <= m) update(x->l, lx, m, i, v);
    else update(x->r, m+1, rx, i, v);
    x->val = (x->l ? x->l->val : 0) + (x->r ? x->r->val : 0);
}
int query(Node* x, int lx, int rx, int l, int r) {
    if (!x || lx > r || rx < l) return 0;
    if (lx >= l && rx <= r) return x->val;
    int m = (lx + rx) / 2;
    return query(x->l, lx, m, l, r) + query(x->r, m+1, rx, l, r);
}