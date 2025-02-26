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

vector<int> coord_comp;
int get_compressed(int x){
    return 
        lower_bound(all(coord_comp), x) 
        - 
        coord_comp.begin();
}
void solve(){
    freopen("in.in", "rt", stdin);
    int n, q;
    cin >> n;
    while(true){
        cin >> q;
        // if (n == 10 && q == 3)
        //     q = 4;
        vector<tuple<int, int, int>> queries;
        coord_comp.clear();
        for (int i = 0; i<q; i++){
            int l, r, t;
            string s;
            cin >> l >> r >> s;
            coord_comp.push_back(--l);
            coord_comp.push_back(--r);
            t = (s[0] == 'e' ? 0 : 1);
            queries.push_back({l, r, t});
        }
        // coordinate compression
        sort(all(coord_comp));
        coord_comp.erase(unique(all(coord_comp)), coord_comp.end());
        print(coord_comp);

        vector<int> lst(coord_comp.size() + 1);
        int ans = q;

        for (int qq = 0; qq<q; qq++){
            auto [l, r, t] = queries[qq];
            // print(qq, l, r);
            l = get_compressed(l);
            r = get_compressed(r);
            print(l, r, t);
            // print(get_compressed(l), get_compressed(r), t);
            if (t) { // odd
                int sum = 0, has_zero = -1;
                for (int i = l; i <= r; i++){
                    sum += (lst[i] == -1 ? 0 : lst[i]);
                    if (!lst[i])
                        has_zero = i;
                }
                if (sum%2 == 0 && has_zero == -1){
                    ans = qq;
                    break;
                }
                for (int i = l; i <= r; i++){
                    if (has_zero != i && !lst[i])
                        lst[i] = -1;
                }
                if (~has_zero){
                    lst[has_zero] = 1;
                }
            } else { // even
                int sum = 0, has_zero = -1;
                for (int i = l; i <= r; i++){
                    sum += (lst[i] == -1 ? 0 : lst[i]);
                    if (!lst[i])
                        has_zero = i;
                }
                if (sum&1 && has_zero == -1){
                    ans = qq;
                    break;
                }
                for (int i = l; i <= r; i++){
                    if (!lst[i] && i != has_zero)
                        lst[i] = -1;
                }
                lst[has_zero] = 1;
            }
            print(lst);
        }
        cout << ans;
        cin >> n;
        if (n == -1)
            return;
        cout << '\n';
    }
}