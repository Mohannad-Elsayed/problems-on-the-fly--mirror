#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <int> v0,v1,v2,v3;
    for (auto x : v0) {
        cin >> v0[x];
        if (v0[x] == 1) v1.push_back(x+1);
        else if (v0[x] == 2) v2.push_back(x+1);
        else v3.push_back(x+1);
    }
    int validTeams = min({v1.size(),v2.size(),v3.size()}); 
    cout << validTeams;
    while (validTeams--) {
        cout << v1.back() << " " << v2.back() << " " << v3.back() << endl;
        v1.pop_back();
        v2.pop_back();
        v3.pop_back();
    }
    return 0;
}