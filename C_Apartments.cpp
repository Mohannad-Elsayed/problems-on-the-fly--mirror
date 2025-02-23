#include <bits/stdc++.h>

#define nl endl
#define ll long long

using namespace std;
#include "cleanup/debug.h"
int main() {

    int n , m ;
    ll k;
    cin >> n >> m >> k;

    vector <ll> a(n) , b(m);
    
    
    for ( int i = 0 ; i < m ; i++ ) 
        cin >> b[i];
    
    for ( int i = 0 ; i < n ; i++ ) 
        cin >> a[i];

    sort ( a.begin() , a.end() );
    sort ( b.begin() , b.end() );
    print(a);
    print(b);
    int i = 0 , j = 0 , cnt = 0;

    while ( i < n && j < m ) {
        ll l = a[i] - k;
        ll r = a[i] + k;

        if ( l <= b[j] && b[j] <= r ) {
            print(n, m, i, j, a[i], b[j]);
            i++;
            j++;
            cnt++;
        }

        else if ( a[i] < b[j] ) {
            i++;
        }

        else {
            j++;
        }
    }

    cout << cnt;

    return 0;
}