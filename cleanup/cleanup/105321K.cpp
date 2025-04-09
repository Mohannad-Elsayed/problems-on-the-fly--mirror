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
    vector<string> v(n);
    each(s, v)
        cin >> s;
    int t, a, p;
    t = a = p = 0;
    reverse(all(v));
    each(s, v)
        reverse(all(s));

    auto printg = [&]() {
        #ifndef ONLINE_JUDGE    
        each(s, v)
            cout << s << '\n';
        cout << "\n\n";
        #endif
    };

    vector<string> T = 
    {
        ".#.",
        ".#.",
        ".#.",
        ".#.",
        "###"
    };
    vector<string> A = 
    {
        "#.#",
        "#.#",
        "###",
        "#.#",
        "###",
    };
    vector<string> P = 
    {
        "..#",
        "..#",
        "###",
        "#.#",
        "###",
    };
    printg();

    #define elif else if 
    auto match = [&](int i, int j, char c) {
        if (i+5 > n || j+3 > m)
            return false;

        vector<string> mask;
        if (c == 'A')
            mask = A;
        else if (c == 'T')
            mask = T;
        else 
            mask = P;
    
        // print(c, mask);
        for (int l = 0; l<5; l++) 
            for (int k = 0; k<3; k++) 
                if (mask[l][k] == '#' && v[i+l][j+k] != '#')
                    return false;

        for (int l = 0; l<5; l++)
            for (int k = 0; k<3; k++) 
                if (mask[l][k] == '#') 
                    v[i+l][j+k] = '.';
        // printg();
        return true;
    };

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (match(i, j, 'P'))
                printg(),p++;
            elif (match(i, j, 'A'))
                printg(),a++;
            elif (match(i, j, 'T'))
                printg(),t++;
        }
    }

    cout << t << ' ' << a << ' ' << p;

}

/*
.............
...#.#.#..#..
...#.#.#..#..
.###.###..#..
.#.#.#.#..#..
.###.###.###.
.............


*/