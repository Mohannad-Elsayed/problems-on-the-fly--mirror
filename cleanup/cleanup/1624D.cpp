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

void solve() {
    int n, k; string s; 
    cin >> n >> k >> s;
    int cnt[256]{};
    each(ch, s)
        cnt[ch]++;
    
    vector<string> f;
    for (int i = 'a'; i<='z'; i++){
        if (!cnt[i])
            continue;
        string ss(cnt[i], i);
        f.push_back(ss);
    }
    sort(all(f), [&](string a, string b){
        return a.size() > b.size();
    });
    s = "";
    each(ss, f)
        s += ss;
    
    cout << s;
}