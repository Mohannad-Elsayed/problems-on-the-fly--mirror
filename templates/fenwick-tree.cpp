#include<bits/stdc++.h>
using namespace std;

class FNWK {
    public:
    using ll = long long;
    vector<ll> bit;
    int skipvalue = 0;
    int N;
    template <typename T>
    void operation(T &source, T &add){ //! change operation
        source = source + add;
    }
    FNWK(){}
    FNWK(int n) {
        N = n;
        bit = vector<ll>(N+2, skipvalue);
    }
    void update(int idx,ll val) { // 0-based
        val -= query(idx, idx);
        idx++;
        while(idx<=N) {
            operation(bit[idx], val);
            idx += idx & -idx;
        }
    }
    ll prefix(int idx) { // 0-based
        idx++;
        ll ret=skipvalue;
        while(idx>0) {
            operation(ret, bit[idx]);
            idx -= idx & -idx;
        }
        return ret;
    }
    ll query(int l,int r) { // 0 based
        return prefix(r) - prefix(l-1); 
    }
};