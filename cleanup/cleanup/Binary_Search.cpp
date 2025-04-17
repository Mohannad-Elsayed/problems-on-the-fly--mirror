#include <bits/stdc++.h>
#include<iostream>
using namespace std;
const long long int N =1e6+1;
typedef long long int ll;
#define mariam ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
#define oo 1e18
void solve() {
    ll n, l;
    cin >> n >> l;
    ll a[n + 1];
    for (ll i = 0; i < n;i++){
        cin >> a[i];
    }
    while(l--){
        ll x;
        cin >> x;
        ll l = 0, r = n - 1,ans=-1;
        while(l<=r){
            ll mid = (l + r) / 2;
            if(a[mid]<x){
                l = mid + 1;
            }
            else if(a[mid]>x)
            {
                r = mid - 1;
            }
            else
            {
                ans = mid + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}
int main() {
    mariam;
    /*ll t; cin>>t;
    while(t--)*/
        solve();
    return 0;
}