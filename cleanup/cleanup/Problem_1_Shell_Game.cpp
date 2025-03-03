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
#define each(x, v) for (auto &(x) : (v))
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // cin >> tt;
    freopen("shell.in", "rt", stdin);
    freopen("shell.out", "wt", stdout);
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
struct step {
    int a, b, g;
};
void solve(){
    int n; cin >> n;
    vector<int> shells(4), guess(4);
    iota(all(shells), 0);
    for (int i = 0; i<n; i++){
        int a, b, g;
        cin >> a >> b >> g;
        swap(shells[a], shells[b]);
        guess[shells[g]]++;
        print(guess);
    }
    cout << *max_element(all(guess));
}