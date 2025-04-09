#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll x = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x *= a[i];
        
        ll sq = sqrt(x);
        if (sq * sq == x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}