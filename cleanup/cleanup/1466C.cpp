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
#define each(x, v) for (auto &(x) : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
void solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}
 
void slv(){
	string s;cin>>s;
	char a='?',b='?';
	int ans=0;
	for(auto c:s){
        print(a, b, c);
		if(c==a||c==b){
			ans++;
			c='?';
		}
		a=b;
		b=c;
	}
	print(ans);
}

void solve() {
    slv();
    return;
    string s; cin >> s;
    int n = (int) s.size();
    vector<int> used(n);
    for (int i = 1; i<n; i++) 
        used[i] = (!used[i-1] && s[i] == s[i-1]) || (i > 1 && !used[i-2] && s[i] == s[i-2]);
    print(used);
    cout << accumulate(all(used), 0);
}