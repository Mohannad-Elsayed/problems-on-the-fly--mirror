#define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
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
#define int long long
void solve(){
    string s; cin >> s;
    vector<int> v(256);
    for (int i = 'a'; i<='z'; i++)
        cin >> v[i];
    // print(v);
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] == '?'){
            char ch1 = (i ? s[i-1] : -1), 
                ch2 = -1, chf;
            int j = i;
            while(j < n && s[j] == '?')
                j++;
            if (j != n)
                ch2 = s[j];
            print(i, j, ch1, ch2);
            int mn = 1e9;
            for (int c = 'a'; c <= 'z'; c++){
                int curr = 0;
                if (~ch1)
                    curr += abs(v[ch1] - v[c]);
                if (~ch2)
                    curr += abs(v[c] - v[ch2]);
                if (curr < mn){
                    mn = curr;
                    chf = c;
                }
            }
            for (int c = i; c < j; c++)
                s[c] = chf;
        }
    }
    int cost = 0;
    for (int i = 0; i+1 < n; i++)
        cost += abs(v[s[i]] - v[s[i+1]]);
    print(cost, s);
    cout << cost << '\n';
    kill(s);
}