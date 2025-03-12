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

void solve() {
    int n; cin >> n;
    int arr[n];
    string s;
    each(i, arr)
        cin >> i;
    cin >> s;
    vector<pair<char, int>> vp(n);
    for (int i = 0; i<n;i++)
        vp[i].first = s[i], vp[i].second = arr[i];
    
    sort(all(vp));
    print(vp);
    for (int i = 1; i<=n; i++) {
        if (vp[i-1].first == 'B') {
            if (vp[i-1].second < i)
                kill("NO");
        }
        else {
            if (vp[i-1].second > i)
                kill("NO");
        }
    }
    cout << "YES";
}