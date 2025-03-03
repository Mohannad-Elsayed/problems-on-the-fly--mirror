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
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int N;
    while (cin >> N && N){
        // int n; cin >> n;
        vector<int> v(N), stk, ans;
        each(i, v)
            cin >> i;
        
        each(i, v){
            while(stk.size() && stk.back() < i){
                ans.push_back(stk.back());
                stk.pop_back();
            }
            stk.push_back(i);
            print(stk);
        }
        while(stk.size())
            ans.push_back(stk.back()), stk.pop_back();
        cout << (is_sorted(all(ans)) ? "yes" : "no") << '\n';
    }

}