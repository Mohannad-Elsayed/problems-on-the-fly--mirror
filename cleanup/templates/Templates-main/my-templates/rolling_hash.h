// Rolling Hash (double hash, prefix queries)
const int N = 2e5+5, B1 = 31, B2 = 69, MOD = 1e9+7;
int pb1[N], pb2[N];
void init_hash() {
    pb1[0]=pb2[0]=1;
    for(int i=1;i<N;i++) pb1[i]=1LL*pb1[i-1]*B1%MOD, pb2[i]=1LL*pb2[i-1]*B2%MOD;
}
struct Hash {
    int h1=0,h2=0,len=0;
    Hash() {}
    Hash(char c): h1(c%MOD), h2(c%MOD), len(1) {}
    Hash operator+(char c) const {
        return {(int)((1LL*h1*B1+c)%MOD),(int)((1LL*h2*B2+c)%MOD),len+1};
    }
    Hash operator+(const Hash& o) const {
        return {(int)((1LL*h1*pb1[o.len]+o.h1)%MOD),(int)((1LL*h2*pb2[o.len]+o.h2)%MOD),len+o.len};
    }
};
vector<Hash> build_hash(const string& s) {
    vector<Hash> h(s.size());
    h[0]=Hash(s[0]);
    for(int i=1;i<s.size();i++) h[i]=h[i-1]+s[i];
    return h;
}
Hash get_hash(const vector<Hash>& h, int l, int r) { // [l,r]
    if(l==0) return h[r];
    int L=r-l+1;
    return {(int)((h[r].h1-1LL*h[l-1].h1*pb1[L]%MOD+MOD)%MOD),
            (int)((h[r].h2-1LL*h[l-1].h2*pb2[L]%MOD+MOD)%MOD),L};
}