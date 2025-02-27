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

#define int ll
void solve(){
    int n, a, b; cin >> n >> a >> b;
    vector<int> ans(n, -1);
    multiset<pair<int, int>> nums;
    set<int> takena, takenb;
    for (int i = 0; i<n; i++){
        pair<int, int> pi;
        cin >> pi.first, pi.second = i;
        nums.insert(pi);
    }
    
    // if (n%2)
    //     kill("NO");
    
    // print(nums);

    int cnt = 0;
    while(nums.size()){
        auto [cn, ci] = *nums.begin(); // current element
        nums.erase(nums.begin());
        if (a-cn == cn){
            ans[ci] = 0;
            takena.insert(cn);
            cnt++;
            continue;
        }
        if (b-cn == cn){
            ans[ci] = 1;
            takenb.insert(cn);
            cnt++;
            continue;
        }
        // search for a-x, b-x elements;
        auto sa = nums.lower_bound(make_pair(a-cn, -1));
        auto sb = nums.lower_bound(make_pair(b-cn, -1));
        int founda = takena.count(a-cn);
        int foundb = takenb.count(b-cn);
        if (founda){
            ans[ci] = 0;
            cnt++;
            continue;
        }
        if (foundb){
            ans[ci] = 1;
            cnt++;
            continue;
        }
        if (sa == nums.end() && sb == nums.end()){
            // print()
            kill("NO");
        }
        if (sa != nums.end() && (*sa).first == a-cn){
            auto [an, ai] = *sa;
            // if (a-cn != an) {
            //     print(a, cn, a-cn, an);
            //     continue;
            // }
            // 4 5 6
            // 1 4 2 4
            nums.erase(sa);
            ans[ci] = ans[ai] = 0;
            takena.insert(an);
            cnt += 2;
        } else if (sb != nums.end() && (*sb).first == b-cn) {
            auto [bn, bi] = *sb;
            // if (b-cn != bn) {
            //     print(b, cn, b-cn, bn);
            //     continue;
            // }
            nums.erase(sb);
            ans[ci] = ans[bi] = 1;
            takenb.insert(bn);
            cnt += 2;
        }
    }

    print(cnt);
    if (cnt != n)
        kill("NO");
    print(ans);
    cout << "YES" << '\n';
    each(i, ans)
        cout << i << ' ';
}