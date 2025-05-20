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
    freopen("inc.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
istream &operator>>(istream &is,__int128_t &v) {
    string s;
    is>>s;
    v=0;
    for(auto &it:s) if(isdigit(it)) v=v*10+it-'0';
    if(s[0]=='-') v*=-1;
    return is;
}

ostream &operator<<(ostream &os,const __int128_t &v) {
    if(v==0) return (os<<"0");
    __int128_t num=v;
    if(v<0) os<<'-',num=-num;
    string s;
    for(;num>0;num/=10) s.push_back((char)(num%10)+'0');
    reverse(all(s));
    return (os<<s);
}


void solve() {
    int arr[26];
    __int128_t sum=0;
    for(int i=0;i<26;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    __int128_t ans=0;
    __int128_t l=1,r=1e12;
    while (l<=r){
        __int128_t mid=l+(r-l)/2;
        if((mid*(mid+1))/2<=sum){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    
}