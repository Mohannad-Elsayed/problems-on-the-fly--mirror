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

namespace RollingHash {
    const int N = 100'100, b1 = 31, b2 = 69, mod = 1e9 + 7, b1I = 129032259, b2I = 579710149;

    vector<int> Pb1(N + 1), Pb2(N + 1);
    char init = []() {
        Pb1[1] = b1, Pb2[1] = b2;
        for (int i = 2; i <= N; i++) {
            Pb1[i] = int(1LL * Pb1[i - 1] * b1 % mod);
            Pb2[i] = int(1LL * Pb2[i - 1] * b2 % mod);
        }
        return char();
    }();

    struct Hash : array<int, 3> {
#define me (*this)
        Hash() : array() { }
        Hash(const array<int, 3> &x) : array(x) { }
        Hash(int x) : array({x % mod, x % mod, 1}) { }

        Hash(const string &x) : array() {
            for(char c : x) *this = *(this) + c;
        }

        void pop_front(int x) {
            me[0] = int((me[0] - 1LL * Pb1[--me[2]] * x % mod + mod) % mod);
            me[1] = int((me[1] - 1LL * Pb2[me[2]] * x % mod + mod) % mod);
        }

        void pop_back(int x) {
            me[0] = int((1LL * (me[0] - x + mod) * b1I) % mod);
            me[1] = int((1LL * (me[1] - x + mod) * b2I) % mod);
            me[2]--;
        }

        void clear() {
            me[0] = me[1] = me[2] = 0;
        }

        friend Hash operator+(const Hash &f, const Hash &o) {
            return array{int((1LL * f[0] * Pb1[o[2]] + o[0]) % mod),
                         int((1LL * f[1] * Pb2[o[2]] + o[1]) % mod)
                    , f[2] + o[2]};
        }
#undef me
    };

    struct HashRange {
        vector<Hash> p, s;
        HashRange(const string &t) : p(t.size()), s(t.size()) {
            p.front() = t.front();
            for(int i = 1; i < t.size(); i++) {
                p[i] = p[i - 1] + t[i];
            }
            s.back() = t.back();
            for(int i = int(t.size()) - 2; i >= 0; i--) {
                s[i] = s[i + 1] + t[i];
            }
        }
        Hash get(int l, int r) {
            if(l > r) return {};
            if(!l) return p[r];
            return array{int((p[r][0] - p[l - 1][0] * 1LL * Pb1[r - l + 1] % mod + mod) % mod),
                         int((p[r][1] - p[l - 1][1] * 1LL * Pb2[r - l + 1] % mod + mod) % mod)
                    , r - l + 1};
        }
        Hash inv(int l, int r) {
            if(l > r) return {};
            if(r + 1 == s.size()) return s[l];
            return array{int((s[l][0] - s[r + 1][0] * 1LL * Pb1[r - l + 1] % mod + mod) % mod),
                         int((s[l][1] - s[r + 1][1] * 1LL * Pb2[r - l + 1] % mod + mod) % mod)
                    , r - l + 1};
        }
    };
}
//using namespace RollingHash;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("strings.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        // if(tt) cout << '\n';
    }return 0;
}

void solve() {
    string s, t; cin >> s >> t;
    int q; cin >> q;
    RollingHash::HashRange hs(s);
    RollingHash::HashRange ht(t);
    map<char, vector<int>> mp;
    for (int i = 0; i<s.size(); i++)
        mp[s[i]].push_back(i);
    
    while(q--) {
        int ans = 0, mx = -1;
        int l, r, i, j;
        cin >> l >> r >> i >> j;
        l--,r--,i--,j--;
        int size1 = r-l+1, size2 = j-i+1;
        each(idx, mp[t[l]]) {
            print(idx);
            // if (idx <= mx)
            //     continue;
            auto hashtlr = ht.get(l, r);
            auto hashtij = ht.get(i, j);
            auto hashslr = hs.get(idx, idx+r-l);
            print(hashslr);
            print(hashtlr);
            if (hashslr == hashtlr) {
                auto hashsij = hs.get(idx+r-l+1, idx+r-l+1+j-i);
                print(hashsij);
                print(hashtij);
                if (hashsij == hashtij) {
                    mx = idx+r-l+1+j-i;
                    print(mx);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}