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
__int128 can(__int128 r, __int128 l) {
    __int128 tor = r*(r+1)/2;
    __int128 tol = l*(l-1)/2;
    return tor-tol;
}
void solve() {
    multiset<int> ste, ste2;
    for (int i = 0; i<26; i++) {
        int x; cin >> x; 
        ste.insert(x);
    }

    int globalans = 0;
    while(ste.size()) {
        //print(ste);
        auto it = ste.rbegin();
        __int128 l = globalans, r = 1e16, mid, ans = -1;
        while (l <= r) {
            mid = (l+r)/2;
            if (can(mid, globalans+1) <= *it) {
                ans = mid;
                l = mid+1;
            } else r = mid-1;
        }
        print(ans);
        int newans = *it - can(ans, globalans+1);
        if (ans == -1||globalans>=ans){
            ste2.insert(*it);
            ste.erase(ste.find(*it));
        }
        else {
            globalans += ans - globalans;
            print(*it,globalans,newans, ans);        
            ste.erase(ste.find(*it));
        }
    }
    print(ste2);
    for(int i=0;i<10;++i){
        int cur=0;
        if((globalans+1)%2==0){
            while(ste2.size()){
                auto it=*ste2.rbegin();
                if(it&1&&cur+it-1<=globalans+1){
                    cur+=it-1;
                    ste2.erase(ste2.find(it));
                    ste2.insert(1);
                }
                else if(it%2==0&&cur+it<=globalans+1){
                    cur+=it;
                    ste2.erase(ste2.find(it));
                }
                else break;
            }
            if(ste2.size()){
                auto it=*ste2.rbegin();
                int z=globalans+1-cur;
                if(z<=it){
                    ste2.insert(it-z);
                    ste2.erase(ste2.find(it));
                    cur+=z;
                }
            }
        }
        else{
                bool odd=0;
                while(ste2.size()){
                auto it=*ste2.rbegin();
                if(it%2==1&&odd==0&&cur+it<=globalans+1){
                    cur+=it;
                    ste2.erase(ste2.find(it));
                }
                else if(it%2==1&&odd==1&&cur+it-1<=globalans+1){
                    cur+=it-1;
                    ste2.erase(ste2.find(it));
                    ste2.insert(1);
                }
                else if(it%2==0&&odd==0&&cur+it<=globalans+1)
                {
                    cur+=it;
                    ste2.erase(ste2.find(it));
                }
                else if(it%2==0&&odd==1&&cur+it-1<=globalans+1)
                {
                    cur+=it-1;
                    ste2.erase(ste2.find(it));
                    ste2.insert(1);
                }
                else break;
            }
            if(ste2.size()){
                auto it=*ste2.rbegin();
                int z=cur-it;
                if(z<=0)continue;
                ste2.insert(it-z);
                ste2.erase(ste2.find(it));
            }
        }
        if(cur==globalans+1)globalans++;
    }
    print(ste2);
    cout << globalans;
}