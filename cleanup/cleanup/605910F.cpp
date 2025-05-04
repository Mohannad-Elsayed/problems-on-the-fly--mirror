#define ONLINE_JUDGE
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
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen("neat.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    string s; int x; 
    cin >> s >> x;
    reverse(all(s));
    vector<string> segs(1);
    while(s.size()) {
        while (s.size() && s.back() == '0') {
            segs.emplace_back("0");
            segs.emplace_back("");
            s.pop_back();
        }
        while(s.size() && s.back() != '0' && (segs.back().empty() || segs.back().back() <= s.back())) {
            segs.back().push_back(s.back());
            s.pop_back();
        }
        if (s.size() && s.back() != '0') {
            segs.push_back("");
            segs.back().push_back(s.back());
            s.pop_back();
        }
    }

    print(segs);
    int segsize = segs.size();
    each(seg, segs)
        if (seg.empty())
            segsize--;
    if (segsize > x)
        kill(-1);

    int need = x - segsize;
    print(need);
    each(seg, segs) {
        if (seg.empty())
            continue;
        int i = 0;
        while(need > 0 && i < seg.size()) {
            cout << seg[i++] << ' ';
            need--;
        }
        need++;
        if (i < seg.size()) {
            need--;
            for (;i<seg.size(); i++)
                cout << seg[i];
            cout << ' ';
        }
    }
}