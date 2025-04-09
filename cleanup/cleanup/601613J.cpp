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
    int n;
    cin >> n;
    
    int now = 1;
    vector<int> group(n);
    map<int, pair<int, int>> range;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        x--;
        
        if(x == 0){
            if(n == 1){
                cout << "1 1\n";
            }
            else{
                if(group[x+1]){
                    range[group[x+1]] = {1, range[group[x+1]].second};

                    cout << range[group[x+1]].first << ' ' << range[group[x+1]].second << endl;
                }
                else{
                    group[x] = now;
                    range[now] = {1, 1};
                    now++;

                    cout << "1 1\n";
                }
            }
        }
        else if(x == n-1){
            if(group[x-1]){
                range[group[x-1]] = {range[group[x-1]].first, n};

                cout << range[group[x-1]].first << ' ' << range[group[x-1]].second << endl;
            }
            else{
                group[x] = now;
                range[now] = {n, n};
                now++;

                cout << n << ' ' << n << endl;
            }
        }
        else{
            if(group[x-1] && group[x+1]){

                range[group[x-1]].second = range[group[x+1]].second;
                group[x+1] = group[x-1];
                group[x] = group[x-1];

                cout << range[group[x-1]].first << ' ' << range[group[x-1]].second << endl;
            }
            else if(group[x-1]){
                group[x] = group[x-1];
                range[group[x-1]].second = x+1;

                cout << range[group[x-1]].first << ' ' << range[group[x-1]].second << endl;

            }
            else if(group[x+1]){
                group[x] = group[x+1];
                range[group[x+1]].first = x+1;

                cout << range[group[x+1]].first << ' ' << range[group[x+1]].second << endl;
            
            }
            else{
                group[x] = now;
                range[now] = {x+1, x+1};
                now++;

                cout << x+1 << ' ' << x+1 << endl;
            }
        }
    }
}