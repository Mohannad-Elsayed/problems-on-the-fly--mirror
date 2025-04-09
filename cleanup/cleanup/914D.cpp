#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;

int bgcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

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

class segment_tree{
    private:
        vector<int>seg;int sz,skip=0;
        int merge(int a,int b){return bgcd(a, b);}
        void update(int l,int r,int node,int idx,int val){
            if(l==r){seg[node]=val;return;}
            int mid=(l+r)>>1;
            if(mid<idx) update(mid+1,r,2*node+2,idx,val);
            else update(l,mid,2*node+1,idx,val);
            seg[node]=merge(seg[2*node+1],seg[2*node+2]);
        }
        int query(int l,int r,int node,int lx,int rx){
            if(l>rx||r<lx)return skip;
            if(l>=lx&&r<=rx)return seg[node];
            int mid=(l+r)>>1;
            int a=query(l,mid,2*node+1,lx,rx);
            int b=query(mid+1,r,2*node+2,lx,rx);
            return merge(a,b);
        }
    public:
        segment_tree(){}
        segment_tree(int n){
            sz=1;while(sz<=n)sz<<=1;
            seg=vector<int>(sz<<1,skip);
        }
        void update(int idx,int val){update(0,sz-1,0,idx,val);}
        int query(int l,int r){return query(0,sz-1,0,l,r);}
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, q; cin >> n;
    vector<int> v(n);
    getv(v);
    segment_tree sgt(n);
    for (int i = 0; i<n; i++) {
        sgt.update(i, v[i]);
    }
    cin >> q;
    while(q--) {
        int t, l, r, x;
        cin >> t;
        if (t == 2) {
            print("1here");
            cin >> l >> x;
            l--;
            sgt.update(l, x);
        } else {
            cin >> l >> r >> x;
            l--, r--;
            bool can = 1;
            int mid;
            while(l<=r) {
                mid = (l+r)/2;

                if (sgt.query(l, mid) % x == 0) {
                    // go to v2 range
                    l = mid+1;
                } else if (sgt.query(mid+1, r) % x == 0) {
                    r = mid - 1;
                } else {
                    can = 0;
                    break;
                }
            }
            cout << (can ? "YES" : "NO") << '\n';
        }
    }
}