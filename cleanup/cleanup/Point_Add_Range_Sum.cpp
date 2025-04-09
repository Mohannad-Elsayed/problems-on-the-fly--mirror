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

namespace fastio{
static constexpr unsigned int buf_size=1<<17;
char ibuf[buf_size];
char obuf[buf_size];
unsigned int pil=0,pir=0,por=0;
struct Pre{
  char t[40000];
  constexpr Pre() : t{} {
    for(int i=0;i<10000;i++){
      int n=i;
      for(int j=3;j>=0;j--){
        t[i*4+j]='0'+n%10;
        n/=10;
      }
    }
  }
} constexpr pre;
inline void load(){
  if(pir-pil<=pil)memcpy(ibuf,ibuf+pil,pir-pil);
  else memmove(ibuf,ibuf+pil,pir-pil);
  pir=pir-pil+fread(ibuf+pir-pil,1,buf_size-pir+pil,stdin);
  pil=0;
}
inline void flush(){
  fwrite(obuf,1,por,stdout);
  por=0;
}
inline void rd(char&c){c=ibuf[pil++];}
template<typename T>
inline void rd(T&x){
  if(pil+32>pir)load();
  char c;
  do rd(c); while(c<'-');
  bool neg=false;
  if constexpr(std::is_signed_v<T>){
    if(c=='-'){
      neg=true;
      rd(c);
    }
  }
  x=0;
  while(c>='0'){
    x=x*10+(c&15);
    rd(c);
  }
  if constexpr(std::is_signed_v<T>){
    if(neg)x=-x;
  }
}
inline void wt(char x){obuf[por++]=x;}
template<typename T>
inline void wt(T x){
  if(por+32>buf_size)flush();
  if(x==0){
    wt('0');
    return;
  }
  if constexpr(std::is_signed_v<T>){
    if(x<0){
      wt('-');
      x=-x;
    }
  }
  if(x>=10000000000000000){
    unsigned int r1=x%100000000;
    unsigned long long q1=x/100000000;
    unsigned int r2=q1%100000000;
    unsigned int q2=q1/100000000;
    unsigned int n1=r1%10000,n2=r1/10000,n3=r2%10000,n4=r2/10000;
    if(x>=1000000000000000000){
      memcpy(obuf+por,pre.t+(q2<<2)+1,3);
      memcpy(obuf+por+3,pre.t+(n4<<2),4);
      memcpy(obuf+por+7,pre.t+(n3<<2),4);
      memcpy(obuf+por+11,pre.t+(n2<<2),4);
      memcpy(obuf+por+15,pre.t+(n1<<2),4);
      por+=19;
    }
    else if(x>=100000000000000000){
      unsigned int q3=(q2*205)>>11;
      unsigned int r3=q2-q3*10;
      obuf[por]='0'+q3;
      obuf[por+1]='0'+r3;
      memcpy(obuf+por+2,pre.t+(n4<<2),4);
      memcpy(obuf+por+6,pre.t+(n3<<2),4);
      memcpy(obuf+por+10,pre.t+(n2<<2),4);
      memcpy(obuf+por+14,pre.t+(n1<<2),4);
      por+=18;
    }
    else{
      obuf[por]='0'+q2;
      memcpy(obuf+por+1,pre.t+(n4<<2),4);
      memcpy(obuf+por+5,pre.t+(n3<<2),4);
      memcpy(obuf+por+9,pre.t+(n2<<2),4);
      memcpy(obuf+por+13,pre.t+(n1<<2),4);
      por+=17;
    }
  }
  else{
    static char buf[12];
    int i=8;
    while(x>=10000){
      memcpy(buf+i,pre.t+((x%10000)<<2),4);
      x/=10000;
      i-=4;
    }
    if(x<100){
      if(x<10)obuf[por++]='0'+x;
      else{
        obuf[por]='0'+x/10;
        obuf[por+1]='0'+x%10;
        por+=2;
      }
    }
    else{
      if(x<1000){
        memcpy(obuf+por,pre.t+(x<<2)+1,3);
        por+=3;
      }
      else{
        memcpy(obuf+por,pre.t+(x<<2),4);
        por+=4;
      }
    }
    memcpy(obuf+por,buf+i+4,8-i);
    por+=8-i;
  }
}
struct Dummy{
  Dummy(){std::atexit(flush);}
}dummy;
}
using fastio::rd;
using fastio::wt;

template<typename T>
struct binary_indexed_tree {
  static_assert(std::is_integral_v<T>);
private:
  static constexpr T Dval = 0;
  T combine(T x, T y) {
    return x + y;
  }
  static constexpr unsigned int t_size=sizeof(T)*8;
  static constexpr unsigned int buf_size=512/t_size;
  static constexpr unsigned int shift=__builtin_ctz(buf_size);
  struct Pre{
    T mask[buf_size*buf_size];
    constexpr Pre(){
      for(int i=0;i<buf_size;i++){
        for(int j=0;j<buf_size;j++){
          if(i<j)mask[i*buf_size+j]=-1;
          else mask[i*buf_size+j]=0;
        }
      }
    }
  }static constexpr pre{};
  T **dat;
  int n,logsn;
public:
  explicit binary_indexed_tree(int n_):n(n_),logsn(0){
    int z=1;
    while(z<n){
      z<<=shift;
      logsn++;
    }
    dat=new T*[logsn+1];
    z=n;
    for(int i=logsn;i>=0;i--){
      const unsigned int now_size=(z+buf_size-1)&~(buf_size-1);
      dat[i]=new T[now_size];
      memset(dat[i],Dval,now_size*sizeof(T));
      z=(z+buf_size-1)>>shift;
    }
  }
  inline void add(int i,const T x){
    for(int j=logsn;j>=0;j--){
      const int buf_id=i&~(buf_size-1);
      const int l=i&(buf_size-1);
      for(int k=0;k<buf_size;k++){
        dat[j][buf_id+k]+=x&pre.mask[(l<<shift)+k];
      }
      i>>=shift;
    }
  }
  inline void set(int i,const T x){
    add(i, x - query(i, i+1));
  }
  inline T query(int l,int r)const{
    T res=0;
    r++;
    for(int j=logsn;l<r;j--){
      res+=dat[j][r]-dat[j][l];
      l>>=shift,r>>=shift;
    }
    return res;
  }
};

void solve() {
    int n, m, t, a, b; 
    rd(n), rd(m);
    binary_indexed_tree<ll> bit(n);
    for (int i = 0; i<n; i++) {
        rd(a);
        bit.set(i, a);
    }
    while(m--) {
        rd(t), rd(a), rd(b);
        if (t) {
            cout << bit.query(a, b-1) << '\n';
        } else {
            bit.add(a, b);
        }
    }
}