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
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif

int pre();int solve(int, vector<int>);
int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    // cin >> tt;
    while(tt--){
        pre();
        // solve();
        // if(tt) cout << '\n';
    }return 0;
}
int slv2(int _n, vector<int> v);
ll pow(ll a, ll b){
    ll res = 1;
    for (int i = 0; i<b; i++){
        res *= a;
    }
    return res;
}
int cnt = 0;
int pre(){
    srand(time(0));
    int n = rand()%3 + 1;
    vector<int> v(n);
    each(i, v)
        i = pow(2, rand()%3 + 1) * pow(3, rand()%3 + 1);
    if (solve(n, v) != slv2(n, v)){
        print(n);
        print(v);
        print(solve(n, v));
        print(slv2(n, v));
    }
    else
        if (cnt%100==0){print(n, v); cnt++;}
    
    //________________________
    return 0;
}
int solve(int n, vector<int> v){
    // int n;
    // vector<int> v(n);
    // each(i, v)
    //     cin >> i;
    
    vector<map<int, int>> vmp;
    vector<int> twos, threes;
    each(ele, v){
        int ti = ele, cnttw = 0, cntth = 0;
        while(ti%2==0)
            ti /= 2, cnttw++;
        while(ti%3==0)
            ti /= 3, cntth++;
        map<int, int> mp;
        for (ll i = 2; i*i <= ti; i++){
            while(ti%i==0)
                ti /= i, mp[i]++;
        }
        if (ti != 1)
            mp[ti]++;
        vmp.push_back(mp);
        twos.push_back(cnttw);
        threes.push_back(cntth);
    }
    sort(all(vmp));
    // print(vmp);
    if (vmp.back() != vmp.front())
        return -1;
    sort(all(twos));
    sort(all(threes));
    // print(twos);
    // print(threes);
    // cout << accumulate(all(twos), 0ll) + 
    //         accumulate(all(threes), 0ll) - 
    //         n * (twos.front() + threes.front());
    //________________________
    return accumulate(all(twos), 0) + 
            accumulate(all(threes), 0) - 
            n * (twos.front() + threes.front());;
}


// #include<bits/stdc++.h>
// #include "cleanup/debug.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef deque<ll> dqll;
typedef vector<char> vc;
typedef vector <pair <ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef set<ll> sll;
typedef set<ll, greater<ll>> reversesll;
typedef multiset<ll> msll;
typedef multiset<ll, greater<ll>> reversemsll;
typedef unordered_map<ll, ll> umll;

#define all(v) v.begin(), v.end()

int slv2(int _n, vector<int> v){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    ll length = _n, cntr = 0, div = 0;
    // cin >> length;
    // vll v(length);
    sll st;

    for(int i = 0; i < length; i++){
        // cin >> v[i];
        st.insert(v[i]);
        if(i>0){
            div=gcd(div, v[i]);
        }else{
            div = v[i];
        }
    }

    // print(div);
    if(st.size() == 1){
        return 0;
    }
    
    for(int i = 0; i < length; i++){
        while(v[i] % 2 == 0 && v[i] > div){
            v[i] /= 2;
            cntr++;
        }
        while(v[i] % 3 == 0 && v[i] > div){
            v[i] /= 3;
            cntr++;
        }
    }
    
    st.clear();
    for(int i = 0; i < length; i++) st.insert(v[i]);
    if(st.size() != 1) return -1;
    else return cntr;
}