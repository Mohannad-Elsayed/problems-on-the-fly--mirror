#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

struct node {
    node *l, *r;
    vector<array<ll, 3>> v;
    explicit node() : l(nullptr), r(nullptr) { }
} *root = new node;

int n, q;
const int N = 2e5 + 1;
vector<int> s(N), a(N), b(N);

void build(node *x, int lx = 0, int rx = n - 1) {
    if(lx == rx) {
        x->v = {{lx, a[lx], b[lx]}};
        return;
    }
    int mid = lx + rx >> 1;
    x->l = new node(), x->r = new node();
    build(x->l, lx, mid);
    build(x->r, mid + 1, rx);

    auto &v = x->v;
    auto &l = x->l->v;
    auto &r = x->r->v;

    v.reserve(l.size() + r.size());

    int i = 0, j = 0;
    while(i < l.size() && j < r.size()) {
        if(s[l[i][0]] < s[r[j][0]]) {
            v.push_back({l[i][0], a[l[i][0]], b[l[i][0]]}); i++;
        }
        else {
            v.push_back({r[j][0], a[r[j][0]], b[r[j][0]]}); j++;
        }
    }
    while(i < l.size()) {
        v.push_back({l[i][0], a[l[i][0]], b[l[i][0]]}); i++;
    }
    while(j < r.size()) {
        v.push_back({r[j][0], a[r[j][0]], b[r[j][0]]}); j++;
    }
    for(int k = 1; k < v.size(); k++) {
        v[k][1] += v[k - 1][1];
    }
    for(int k = int(v.size()) - 2; k >= 0; k--) {
        v[k][2] += v[k + 1][2];
    }
}


bool comp(const array<ll, 3> &i, const array<ll, 3> &j) {
    return s[i[0]] < s[j[0]];
}

int c = 0, lstA, lstB;
ll aa, bb;
void gt(node *x, int lx, int rx, int l, int r) {
    if(l > rx || lx > r) return;
    if(lx >= l && rx <= r) {
        auto it = upper_bound(x->v.begin(), x->v.end(), array<ll, 3>{n, -1, -1}, comp);

        c += int(it - x->v.begin());
        aa += it == x->v.begin()? 0: (*prev(it))[1];
        bb += it == x->v.end()? 0: (*it)[2];
        lstA = max(lstA, it == x->v.begin()? -1: s[(*prev(it))[0]]);
        lstB = min(lstB, it == x->v.end()? n + 1: s[(*it)[0]]);

        return;
    }

    int mid = lx + rx >> 1;
    gt(x->l, lx, mid, l, r);
    gt(x->r, mid + 1, rx, l, r);
}

void TC() {
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    root = new node();
    build(root, 0, n - 1);
    while(q--) {
        int L, R;
        cin >> L >> R, L--, R--;

        int l = 0, r = n + 1;
        while(r > l + 1) {
            int mid = l + r >> 1;
            s[n] = mid;
            aa = bb = c = 0;
            gt(root, 0, n - 1, L, R);
            if(aa >= bb) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        s[n] = r;
        aa = bb = c = 0, lstA = -1, lstB = n + 1;
        gt(root, 0, n - 1, L, R);

        ll bbb = bb;
        s[n] = lstA - 1;
        aa = bb = c = 0, lstA = -1, lstB = n + 1;
        gt(root, 0, n - 1, L, R);

        if(bbb >= aa) {
            c++;
        }
        cout << c << ' ' << R - L + 1 - c << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    for (int test = 1; test <= tc; ++test) {
        TC();
    }
//    cerr << clock() / 1000.0 << " Secs";
    return 0;
}