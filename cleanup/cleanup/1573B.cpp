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

void solve() {
    int n, t, ans = 1e9; cin >> n;
    map<int,int> first_greater; // for each element in a, holds the first element in b that is greater than each element in a

    int a[n], b[n];
    each(i, a)
        cin >> i;
    each(i, b)
        cin >> i;

    deque<int> v;
    for (int i = 1; i<2*n; i+=2)
        v.push_back(i);
    print(v);
    for (int i = 0; i<n; i++)
        while(v.size() && v.front() < b[i]) 
            first_greater[v.front()] = i, v.pop_front();
    print(first_greater);
    for (int i = 0; i<n; i++)
        print(i, a[i], first_greater[a[i]]), chmin(ans, i+first_greater[a[i]]);
    
    cout << ans;

    
    
}