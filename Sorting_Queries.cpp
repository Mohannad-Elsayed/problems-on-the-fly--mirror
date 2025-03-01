// #define ONLINE_JUDGE
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
template<typename T>
using mxpq =  priority_queue<T>;
template<typename T>
using mnpq =  priority_queue<T, vector<T>, greater<T>>;

void solve(){
    int n; 
    cin >> n;
    deque<int> dq;
    mnpq<int> pq;
    while(n--){
        int a, b; cin >> a;
        if (a == 1) {
            cin >> b;
            dq.push_back(b);
        } else if (a == 2) {
            if (pq.size()) {
                cout << pq.top();
                pq.pop();
            } else {
                cout << dq.front();
                dq.pop_front();
            }
            cout << '\n';
        } else {
            each(i, dq)
                pq.push(i);
            dq.resize(0);
        }
    }
}