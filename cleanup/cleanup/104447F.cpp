#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define kill(x) return void(cout << (x));

// Function to read a vector of strings or numbers
template<typename T>
void getv(vector<T>& v) {
    for(auto &x: v)
        cin >> x;
}

void solve() {
    int n, k; 
    cin >> n >> k;
    vector<string> vs(n);
    getv(vs);

    // For each string, calculate the minimum modifications to make it a palindrome.
    vector<int> mnpal(n, 0);
    for (int i = 0; i < n; i++){
        int sz = vs[i].size();
        for (int j = 0; j < sz / 2; j++) {
            if(vs[i][j] != vs[i][sz - j - 1])
                mnpal[i]++;
        }
    }
    
    // Read the scores.
    vector<ll> scores(n);
    getv(scores);
    
    // Use a sliding window from l to r where:
    //   - currCost is the total modifications required
    //   - currScore is the total score of the window
    ll currCost = 0, currScore = 0, ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        currCost += mnpal[r];
        currScore += scores[r];
        
        // Shrink the window from the left until the cost is at most k.
        while (l <= r && currCost > k) {
            currCost -= mnpal[l];
            currScore -= scores[l];
            l++;
        }
        
        // At this point, the window [l, r] is valid.
        ans = max(ans, currScore);
    }
    
    cout << ans;
}

int main(){
    fastio;
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
        cout << '\n';
    }
    return 0;
}
