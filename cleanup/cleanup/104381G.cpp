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
    int n, m; cin >> n >> m;
    deque<pair<int, int>> a(n), b(m), ta, tb;
    each(i, a) { 
        cin >> i.first >> i.second;
        i.second += i.first - 1;
    }
    each(i, b) {
        cin >> i.first >> i.second;
        i.second += i.first - 1;
    }
    sort(all(a));
    sort(all(b));
    ta = a;
    tb = b; 
    int ansa = 1, ansb = 1, curr = 0; // curr -> 0 floor, 1 ceil ^= 1
    // from floor (a)
    // print(a);
    if (a.front().first == 1) {
        while(true) {
            print(a);
            print(b);
            if (curr) {
                while(a.size() && b.front().second > a.front().second) {
                    print(a, curr);
                    a.pop_front();
                }
                if (a.empty()) {
                    ansa += b.front().second-b.front().first+1;
                    break;
                }
                if (b.front().second >= a.front().first && b.front().second <= a.front().second) {
                    a.front().first = b.front().second;
                    b.pop_front();
                }
            }
            else {
                while(b.size() && a.front().second > b.front().second) {
                    // print(a, "in");
                    b.pop_front();
                }
                if (b.empty()) {
                    ansa += a.front().second-a.front().first+1;
                    break;
                }
                if (a.front().second >= b.front().first && a.front().second <= b.front().second) {
                    // print("here");
                    ansa += a.front().second-a.front().first+1;
                    b.front().first = a.front().second;
                    a.pop_front();
                }
                else {
                    break;
                }
            }
            curr ^= 1;
        }   
    }
    a = tb, b = ta, curr = 0;
    if (a.front().first == 1) {
        while(true) {
            print(a);
            print(b);
            if (curr) {
                while(a.size() && b.front().second > a.front().second) {
                    print(a, curr);
                    a.pop_front();
                }
                if (a.empty()) {
                    ansb += b.front().second-b.front().first+1;
                    break;
                }
                if (b.front().second >= a.front().first && b.front().second <= a.front().second) {
                    a.front().first = b.front().second;
                    b.pop_front();
                }
            }
            else {
                while(b.size() && a.front().second > b.front().second) {
                    // print(a, "in");
                    b.pop_front();
                }
                if (b.empty()) {
                    ansb += a.front().second-a.front().first+1;
                    break;
                }
                if (a.front().second >= b.front().first && a.front().second <= b.front().second) {
                    // print("here");
                    ansb += a.front().second-a.front().first+1;
                    b.front().first = a.front().second;
                    a.pop_front();
                }
                else {
                    break;
                }
            }
            curr ^= 1;
        }   
    }

    // print(a);
    // print(b);
    print(ansa, ansb);
    cout << max(ansa, ansb);
}