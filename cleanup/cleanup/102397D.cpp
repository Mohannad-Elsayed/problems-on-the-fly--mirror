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
    ll n,t;
    cin >> n >> t;
    ll a[n],pre[n+1]={0};
    fori(0,n){
        cin >> a[i];
        pre[i+1] = pre[i] + a[i];
    }
    ll dis = LLONG_MAX,total=0,l=0,r=0;
    for(int r=0;r<=n;r++){
        total=pre[r]-pre[l];
        //cout << total << nl;
        if(total < t)
            continue;
        while (l+1 <= r && total-pre[l+1] >= t){
            total-=pre[l+1];
            l++;
        }
        dis = min(dis,r-l+1);
        l--;
    }
    cout << (dis==LLONG_MAX?-1:dis) << nl;
}