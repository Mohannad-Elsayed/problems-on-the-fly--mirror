#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int>a(n);
        for(int &x:a) cin >> x;

        // 1) freq + find initial MEX k
        unordered_map<int,int> freq;
        freq.reserve(n*2);
        for(int x:a) freq[x]++;
        int k = 0;
        while(freq.count(k)) ++k;

        // 2) if k=0 answer is 0
        if(k==0){
            cout << 0 << "\n";
            continue;
        }

        // 3) build freq[0..k-1]
        vector<int> f(k);
        for(int i=0;i<k;i++)
            f[i] = freq[i];  // guaranteed >0 for i<k

        // 4) try finishing each t first
        // S(t) = (f[t]-1)*k + t*(n-f[t]+1)
        ll ans = LLONG_MAX;
        for(int t=0;t<k;t++){
            ll ft = f[t];
            ll St = (ft-1LL)*k + ll(t) * (n - ft + 1);
            ans = min(ans, St);
        }

        cout << (ans ? ans-1 : 0) << "\n";
    }
    return 0;
}