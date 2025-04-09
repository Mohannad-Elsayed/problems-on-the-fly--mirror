#define ONLINE_JUDGE
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
template<class T> void getv(T& v) {each(i, v)cin>>i;}
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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1}; // share one side

vector<string> mat;
vector<pair<int, int>> wolves;
int n, m, w, mx = 0; 
// void bt(int cw = 0) {
//     if (mx == w)
//         return;
//     for (int i = 0; i<4; i++) {
//         if (mat[wolves.])
//     }
// }
struct goat {
    int i, j, g;
    goat(int _i, int _j, int _g) : i(_i), j(_j), g(_g) {}
};
string to_string(goat f) {
    return to_string(f.i) + " " + to_string(f.j) + " || " + to_string(f.g);  
}
void solve() {
    cin >> n >> m;
    mat.resize(n);
    each(i, mat)
        cin >> i, w += count(all(i), 'W');
    print(w);
    vector<goat> vg;
    for (int i = 0; i<n; i++) 
        for (int j = 0; j < m; j++) 
            if (mat[i][j] == 'G')
                vg.push_back(goat(i, j, (i+1 < n && mat[i+1][j] == 'W') + 
                    (i > 0 && mat[i-1][j] == 'W')  +
                    (j+1 < m && mat[i][j+1] == 'W') +
                    (j > 0 && mat[i][j-1] == 'W')));
    sort(all(vg), [&](goat a, goat b){
        return a.g < b.g;
    });
    each(www, vg)
        print(www);
    // print(vg);
    int ans = 0;
    each(www, vg) {
        auto [i, j, g] = www;
        for (int dr = 0; dr < 4; dr++) {
            int ii = i+dx[dr];
            int jj = j+dy[dr];
            if (ii > -1 && ii < n && jj > -1 && jj < m && mat[ii][jj] == 'W') {
                ans++;
                mat[ii][jj] = '.';
                break;
            }
        }
        each(gggg, vg) {
            auto [ii, jj, gg] = gggg;
            for (int dr = 0; dr < 4; dr++) {
                int iii = ii+dx[dr];
                int jjj = jj+dy[dr];
                gggg.g = (iii+1 < n && mat[iii+1][jjj] == 'W') + 
                    (iii > 0 && mat[iii-1][jjj] == 'W')  +
                    (jjj+1 < m && mat[iii][jjj+1] == 'W') +
                    (jjj > 0 && mat[iii][jjj-1] == 'W');
            }

        }
        // each(ss, mat) {
        //     each(ch, ss) cout << ch;cout << '\n';}cout << "\n\n";
    }
    cout << ans;

}