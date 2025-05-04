#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s, t;
    cin >> s >> t;

    // Sort both strings to simplify comparison
    string sorted_s = s;
    string sorted_t = t;
    sort(sorted_s.begin(), sorted_s.end());
    sort(sorted_t.begin(), sorted_t.end());

    // If the sorted versions of the strings are identical, they can be transformed into each other
    if ( sorted_s == sorted_t ) {
        return true;
    }

    // Initialize frequency arrays for the characters 'a' to 'z'
    vector<int> freq_s(30, 0);
    vector<int> freq_t(30, 0);

    // Populate frequency arrays for both strings
    for (char c : s) {
        freq_s[c - 'a']++;
    }
    for (char c : t) {
        freq_t[c - 'a']++;
    }

    int n = s.size();

    // Try to match frequency arrays by transforming characters
    for (int i = 0; i < n * 26 * 3 + 1; ++i) {
        int idx = -1;
        for(int j = 0; j < 30; j ++){
            if(freq_s[j] > 0){
                idx = j;
                break;
            }
        }

        assert( idx != -1 );
        
        freq_s[idx]--;
        freq_s[(idx + 1) % 26]++;
        if (freq_s == freq_t) {
            return true;
        }
    }
    return freq_s == freq_t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while ( tt --> 0 ){
        if (solve()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    

    return 0;
}