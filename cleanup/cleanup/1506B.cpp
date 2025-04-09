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

void solve(){
    int n, k; string s; 
    cin >> n >> k >> s;
    int cnts = count(all(s), '*');
    if (cnts < 3)
        kill(cnts);
    deque<int> indices;
    for (int i = 0; i<n; i++)
        if (s[i] == '*')
            indices.emplace_back(i);
    print(indices);
    indices.pop_front();
    indices.pop_back();
    int ans = 2;
    for (int i = 0; i<indices.size(); i++){
        int curr = -1;
        for (int j = i+1; j < indices.size(); j++){
            if (indices[j] - indices[i] >= k){
                if (curr != -1)
                    ans++;
                i = j-1;
                break;
            }
            curr = indices[j];
        }
    }
    cout << ans;
}