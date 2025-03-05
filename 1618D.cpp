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
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n, k;
    cin >> n >> k;
    deque<int> v(n);
    each(i, v)
        cin >> i;
    sort(all(v));
    int ans = 0;
    while(k--){
        print("b", v,ans);
        int a = v.front(), b = -1;
        while(!v.front()) v.pop_front();
        for (int i = 1; i<v.size(); i++){
            if (v[i] && v[i] > a){
                b = v[i];
                v[i] = 0;
                v.pop_front();
                break;
            }
        }
        if (b == -1){
            v.pop_front();
            each(i, v){
                if (i){
                    i = 0;
                    break;
                }
            }
            ans++;
        }
        print("a", v, ans);
    }
    print(v, ans);
    cout << ans + accumulate(all(v), 0ll);
}