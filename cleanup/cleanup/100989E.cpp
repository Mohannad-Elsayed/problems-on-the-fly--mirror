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

void solve() {
    string a, b; 
    cin >> a >> b;
    if (a.length() < 8) {
        kill(a == b ? "yes" : "no");
    }
    if (a.length() < b.length() || (int)a.length()-(int)b.length() > 1)
        kill("no");
    // now a is bigger than or equal to b by one char only
    // placed it with a wrong character
    if (a.length() == b.length()) {
        int cnt = 0;
        for (int i=0; i<a.length(); i++)
            cnt += a[i] != b[i];
            kill(cnt > 1 ? "no" : "yes");
    }
    // dropped it
    else {
        for (int k = 0; k <= (int)a.size(); k++) {
            // k : how many characters will you match 
            // from the first before dropping 
            int i;
            string kk;
            for (i = 0; i<k; i++) 
                kk.push_back(a[i]);
            for (int j = i+1; j<(int)a.size(); j++) 
                kk.push_back(a[j]);
            print(kk);
            if (kk == b)
                kill("yes");
        }
    }
    cout << "no";
}