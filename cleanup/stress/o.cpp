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
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve(){
    int n; string s; 
    cin >> n >> s;
    vector<int> aindx;
    for (int i = 0; i<n; i++)
        if (s[i] == 'a')
            aindx.emplace_back(i);

    if (aindx.size() < 2)
        kill(-1);
    int mn = 1e9;
    bool f = false;
    for (int i = 0; i+1 < int(aindx.size()); i++){
        int ci = aindx[i], ni = aindx[i+1];
        if (ni-ci > 3)
            continue;
        int cb = 0, cc = 0;
        for (int k = ci+1; k < ni; k++)
            s[k] == 'b' ? cb++ : cc++;
        if (cb < 2 && cc < 2)
            f = true, mn = min(mn, ni-ci+1);
    }
    kill(f ? mn : -1);
}