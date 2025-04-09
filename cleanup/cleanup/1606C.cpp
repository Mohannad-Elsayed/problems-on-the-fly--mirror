// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = unsigned long long;
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
    exit(0);
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

ll pow_int(ll p, ll base){
    ll ans = 1;
    while (base--)
        ans *= p;
    return ans;
}
using u64 = unsigned long long;
// u64 stolll(stirng ss) { 

// }
void solve() {
    ll n, k; 
    cin >> n>> k;
    vector<ll> notes(n), diffs;
    each(i, notes)
        cin >> i;
    for (int i = 1; i < n; i++)
        diffs.push_back(pow_int(10, notes[i]-notes[i-1]) -1);
    print(diffs);
    k++;
    string ans;
    deque<string> anss;
    int i = 0;
    while(k && i+1 < n){
        ll mn = min(diffs[i++], k);
        anss.emplace_back(to_string(mn));
        k -= mn;
    }
    anss.emplace_back(to_string(k));
    reverse(all(anss));
    print(anss);
    
    each(i, anss){
        if (i == "0")
            continue;
        ans += i;
    }
    cout << ans;
}