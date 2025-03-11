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
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
bool is_sub_sequence(string a, string base){
    int i = 0, j = 0;
    for (; i < a.size() && j < base.size(); i++){
        if (base[j] == a[i])
            j++;
    }
    return j == base.size();
}
void solve() {
    string s, t, st;
    cin >> s >> t;
    st = t;
    // sort(all(st));
    sort(all(s));
    print(s);
    if (is_sub_sequence(s, t)){
        char u = t[1], v = t[2];
        // change every u to  v and every v to u
        int cu = count(all(s), u);
        int cv = count(all(s), v);
        each(ch, s)
            if (ch == u || ch == v)
                ch = '-';
        int i = 0;
        while(cv){
            if (s[i] == '-')
                s[i] = v, cv--;
            i++;
        }
        i = 0;
        while(cu){
            if (s[i] == '-')
                s[i] = u, cu--;
            i++;
        }
    }
    cout << s;
}