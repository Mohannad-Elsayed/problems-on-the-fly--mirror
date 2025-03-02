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

void solve(){
    int n; string s; 
    cin >> n >> s;
    int cnt = 0;
    n*=2;
    for (int i = 0; i<n; i++){
        if (s[i] == '-')
            continue;
        for (int j = i+1; j < n; j++){
            if (s[j] == 'W'){
                s[i] = s[j] = '-';
                break;
            }
        }
    }
    print(s);
    n/=2;
    /*
        WWWWRRWRRRRRWRRWRWRRWRRWWWWWWWRWWRWWRRRR
    */
    for(int i = 0; i<n; i++)
        if (s[i] != '-')
            kill("NO");
    cout << "YES";
}