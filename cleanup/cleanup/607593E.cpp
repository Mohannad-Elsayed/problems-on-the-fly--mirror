// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
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
int rnglr(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1}; // king
void solve();

set<set<pair<int, int>>> visitedStates;
set<pair<int, int>> currentState;
int n = 8;  

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

bool areAdjacent(const pair<int, int>& p1, const pair<int, int>& p2) {
    return abs(p1.first - p2.first) <= 1 && abs(p1.second - p2.second) <= 1;
}

bool canAddCell(int x, int y) {
    for (const auto& p : currentState) {
        if (areAdjacent(p, {x, y})) {
            return false;
        }
    }
    return true;
}

void rec(int idx = 0) {
    if (idx == n * n) {
        if (!currentState.empty()) {  // Only add non-empty configurations
            visitedStates.insert(currentState);
        }
        return;
    }
    
    int x = idx / n;
    int y = idx % n;
    
    // Skip this cell
    rec(idx + 1);
    
    // Include this cell if possible
    if (canAddCell(x, y)) {
        currentState.insert({x, y});
        rec(idx + 1);
        currentState.erase({x, y});  // Backtrack
    }
}

void stress() {
    rec();
    print(visitedStates.size());
    exit(0);
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("area.in", "r", stdin);
    int tt = 1;
    stress();
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    
}