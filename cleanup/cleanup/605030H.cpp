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
    string s, stk; cin >> s;
    int n = s.size();
    int pfxo = 0, pfxc = 0, sfxo = count(all(s), '('), sfxc = 0;
    for (int i = n-1; ~i; i--) {
        if (s[i] == ')')
            sfxc++;
        if (s[i] == '(' && sfxc > 0)
            sfxc--;
    }
    print(sfxc);
    each(ch, s) {
        if (ch == '?') {
            print(pfxo, sfxc);
            if (pfxo <= sfxc) {
                ch = '(';
                pfxo++;
            }
            else {
                ch = ')';
                pfxo--;
            }
        }
        else if (ch == '(') {
            pfxo++;
        } else {
            pfxo--;
        }
    }
    print(s);
    each(ch, s) {
        if (ch == ')') {
            if (stk.empty())
                kill("Impossible");
            stk.pop_back();
        } else if (ch == '(')
            stk.push_back('(');
        else 
            kill("Impossible");
    }
    if (stk.size())
        kill("Impossible");
    cout << s;
}