#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return cout << (x), 0;
#define killn(x) return cout << (x) << '\n', 0;

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}
struct comp {
    bool operator() (string a, string b) const{
        if (a.size() != b.size())
            return a.size() < b.size();
        else
            return a < b;
    }
};
int solve2(){
    string s;
    int n = 1;
    cin >> n;
    char curr = 'a';
    set<string, comp> ste;
    for (int i = 0; i < n; i++){
        s.push_back(curr++);
        // print(s);
        sort(all(s));
        do {
            ste.insert(s);
        } while(next_permutation(all(s)));
    }
    print(ste);
    print(ste.size());
    //________________________
    return 0;
}
int solve(){
    // freopen("out.out", "wt", stdout);
    string s = "abbcc";
    cin >> s;
    #define sze 7
    size_t n = s.size();
    set<string, comp> ste;
    for (int i = 1; i < (1 << n); i++){
        string ss; 
        bitset<sze> bts(i);
        for (int j = 0; j<sze; j++)
            if (bts.test(j))
                ss.push_back(s[j]);
        
        // print(bts, ss); 
        string sss = ss;
        sort(all(sss));
        do {
            ste.emplace(sss);
        } while(next_permutation(all(sss)));
    }
    cout << ste.size();

    // print(ste.size());
    // // print(ste);
    // int freq[sze+1]{};
    // for (auto x : ste)
    //     if (x.size() > 4) cout << x << '\n', freq[x.size()]++;
    // for (int i = 1; i<=sze; i++)
    //     cout << i << "  :  " << freq[i]/(sze) << 
    //             ' ' << freq[i] << '\n';
    //------------------------
    return 0;
}