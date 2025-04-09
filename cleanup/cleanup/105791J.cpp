#include <bits/stdc++.h>
using namespace std;
#define Ah_Ya_Alisson_Ah ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el cout << '\n';
#define all(x) x.begin(), x.end()
#define int long long int
const int N = 2e5+6, mod = 1e9 + 7;

void afroos() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<double> freq(k+1);
    vector<int> f(n+1,0);
    vector<vector<int>> comp;
    for(int i=1;i<=m;i++) {
        int a;cin>>a;
        vector<int> v(a);
        for(auto &x:v) cin>>x;
        comp.push_back(v);
    }
    for(int i=1;i<=n;i++) {
        int a;cin>>a;
        a--;
        f[a]++;
    }
    for(int i=0;i<n;i++) {
        if(comp[i].empty())continue;
        for(auto &x:comp[i]) {
            double w=1.0/(int)comp[i].size();
            freq[x]+=freq[i]*w;
        }
    }
    for(int i=1;i<=k;i++)cout<<fixed<<setprecision(10)<<freq[i]<<" ";el;
}
int32_t main() {
    Ah_Ya_Alisson_Ah
    int T=1;
    //cin>>T;
    while(T--)
    afroos();
    return 0;
}