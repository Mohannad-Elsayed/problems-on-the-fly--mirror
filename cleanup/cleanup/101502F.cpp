/*****************************************
██╗░░░░░░█████╗░████████╗███████╗██╗░░░██╗
██║░░░░░██╔══██╗╚══██╔══╝██╔════╝╚██╗░██╔╝
██║░░░░░██║░░██║░░░██║░░░█████╗░░░╚████╔╝░
██║░░░░░██║░░██║░░░██║░░░██╔══╝░░░░╚██╔╝░░
███████╗╚█████╔╝░░░██║░░░██║░░░░░░░░██║░░░
╚══════╝░╚════╝░░░░╚═╝░░░╚═╝░░░░░░░░╚═╝░░░
*****************************************/

/* لو أن الناس كلما استصعبوا أمرًا تركوه، ماقام للناس دنيا ولا دين  - عمر بن عبدالعزيز */

#include <iostream>
#include <bits/stdc++.h>
// #include "cleanup/debug.h"
using namespace std;

#define PleaseNoTL() ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fori(x,n) for(int i=x;i<n;i++)
#define forj(x,n) for(int j=x;j<n;j++)
#define F first
#define S second
#define PB push_back
#define Test int t;cin>>t;while(t--)
#define nl '\n';
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void Meow(){
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    PleaseNoTL();
    //Meow();
    Test{
        ll n,q;
        cin >> n >> q;
        ll a[n],pre[n+1]={0};
        fori(0,n){
            cin >> a[i];
            ll temp = a[i],mini=0;
            while(temp > 1){ 
                mini += (temp%2) + 1;
                temp /= 2;
            }
            pre[i+1]=pre[i]+mini;
        }
        // for (auto i : pre)
        //     cout << i << ' ';
        //     cout << '\n';
        ll l,r;
        fori(0,q){
            cin >> l >> r;
            cout << pre[r]-pre[l-1] << nl;
        }
    }
}
