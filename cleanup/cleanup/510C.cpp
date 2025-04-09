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
    int n; cin >> n;
    vector<string> v(n);
    vector<vector<int>> g(26);
    vector<int> indeg(26);
    auto printg = [&]() {
        for(int i=0;i<26;i++){
            cout<<char(i+'a')<<" : ";
            each(j,g[i])cout<<char(j+'a')<<' ';cout<<'\n';
        }
    };
    getv(v);
    for (int i = 0; i+1 < n; i++) {
        int mn = min(v[i].size(), v[i+1].size());
        string a = v[i], b = v[i+1];
        bool f = 0;
        for (int j = 0; j<mn; j++) {
            if (a[j] != b[j]) {
                g[a[j]-'a'].push_back(b[j]-'a');
                indeg[b[j]-'a']++;
                f = 1;
                break;
            }
        }
        if (!f && a.size() > b.size()) {
            cout << "Impossible";
            exit(0);
        }

    }
    // printg();
    vector<int> vis(26);
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        each(v, g[u]) {
            if (!vis[v])
                dfs(v);

            if (vis[v] == 1) {
                cout << "Impossible";
                exit(0);
            }
        }
        vis[u] = 2;
    };
    string ans;
    vector<int> q;
    for (int i = 0; i<26; i++) {
        if (!vis[i])
            dfs(i);
        if (!indeg[i])
            q.push_back(i);
    }
    while(q.size()) {
        int u = q.back();
        q.pop_back();
        ans.push_back(char(u+'a'));
        each(v, g[u]) {
            indeg[v]--;
            if (!indeg[v])
                q.push_back(v);
        }
    }

    cout << ans;
}

/*
p -> e -> f -> i -> k -> d -> m -> b -> c




b : c 
d : m 
e : f 
f : i 
*/