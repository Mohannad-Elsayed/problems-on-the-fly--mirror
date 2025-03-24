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
template<class T> void getv(T& v) {each(i, v)cin>>i;}
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
    set<char> s1, s2;
    int n; cin >> n;
    vector<string> v(n);
    getv(v);
    for (int i = 0; i<n; i++)
        s1.insert(v[i][i]), v[i][i] = '=';
    for (int i = 0, j = n-1; i < n; i++, j--)
        if (v[i][j] != '=')
            s1.insert(v[i][j]), v[i][j] = '=';
    each(s, v)
        each(ch, s)
            if (ch != '=')
                s2.insert(ch);
    // each(s, v)
    //     cout << s << endl;
    
    // print(s1, s2);
    if (s1.size() == 1 && s2.size() == 1 && *s1.begin() != *s2.begin())
        kill("YES");
    cout << "NO";
}