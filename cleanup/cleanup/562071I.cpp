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

#define int ll

void solve() {
    int q; cin >> q;
    vector<pair<int, int>> qs(q, make_pair(-1, -1));
    for (int i = 0; i<q; i++) {
        cin >> qs[i].first;
        if (qs[i].first == 1)
            cin >> qs[i].second;
    }
    while(qs.back().first == 1)
        qs.pop_back();
    print(qs);
    int cnt2 = 0;
    q = qs.size();
    vector<int> vals, ans;
    for (auto &[a, b] : qs) {
        if (a == 1) 
            vals.emplace_back(b);
        else cnt2++;
    }
    sort(rall(vals));
    map<int, vector<int>> indices;
    for (int i = 0; i<(int)vals.size(); i++) {
        indices[vals[i]].push_back(i);
    }
    print(indices);
    print(vals);
    int ptr = cnt2-1, ptrzeroright = cnt2;
    int sum = accumulate(vals.begin(), vals.begin()+ptr+1, 0ll);
    print(sum);
    for (int i = q-1; ~i; i--) {
        print(ptr, ptrzeroright);
        if (qs[i].first == 1) {
            int to_be_removed = qs[i].second;
            int ind = indices[to_be_removed].back();
            print(to_be_removed, ind);
            indices[to_be_removed].pop_back();
            vals[ind] = 0;
            if(ind < ptr) {
                while(!vals[ptrzeroright])
                    ptrzeroright++;
                sum += vals[ptrzeroright];
                ptrzeroright++;
                ptr = ptrzeroright-1;
                sum -= to_be_removed;
            }
            print(vals);
            print(sum);
        }
        else {
            ans.emplace_back(sum);
            print("2", sum);
            while(!vals[ptr])
                ptr--;
            sum -= vals[ptr];
            // vals[ptr] = 0;
            ptr--;
            ptrzeroright--;
            print("2after", sum);
        }
    }
    reverse(all(ans));
    each(i, ans)
        cout << i << '\n';
}