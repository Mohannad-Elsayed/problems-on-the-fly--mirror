#include<bits/stdc++.h>
// #define print cout << "\n";
#define ll long long int
#define ull unsigned long long
#define all(v) v.begin(),v.end()
#define sz(v) ((ll)((v).size()))
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#include "cleanup/debug.h"
ll xx=1;
void solve()
{
	cout << "Case " << xx << ": ";
	ll min1=LLONG_MAX,fn1=0,fn2=0;
	string x;
	cin >> x;
	map<char,ll>mp;
	ll p1=0,p2=0,tens=0;
	while(p1<x.size())
	{
        print(mp);
		
		while(p2<x.size())
		{
			if((mp.count('1')==1 && mp['1']>1)&&(mp.count('0')==1 && mp['0']>1)&&(mp.size()>=10) && (tens>=1))
				break;
			
			if(x[p2]!='1')
				mp[(char)x[p2]]++;
			else
			{
				if(p2+1<x.size() && x[p2+1]=='0')
				{
					mp['1']++;
					mp['0']++;
					tens++;
					p2++;
					
				}
				else
					mp[x[p2]]++;
			}
			p2++;
		}
		if(mp.size()>=10 && ((mp.count('1') && mp['1']>1)&&(mp.count('0') && mp['0']>1)) &&(tens>=1) )
		{
			if(min1>=p2-p1)
			{
				min1=min(min1,p2-p1);
				fn1=p1+1;
				fn2=p2;
			}
		}
		if(x[p1]!='1')
		{
			mp[x[p1]]--;
		if(mp[x[p1]]==0)
			mp.erase(x[p1]);
		}
		else
		{
			if(p1+1<x.size() && x[p1+1]=='0')
			{
				tens--;
				mp['1']--;
				if(mp['1']==0)
					mp.erase('1');
				if(mp['0']==0)
					mp.erase('0');
			}
			else
			{
				mp[x[p1]]--;
				if(mp[x[p1]]==0)
					mp.erase(x[p1]);
			}
		}
		p1++;

	}
	if(min1==LLONG_MAX)
		cout << "NO";
	else
		cout << "YES " << fn1 << " " << fn2;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    ll t=1;
    cin >> t;
    for( xx=1;xx<=t;xx++)
    {
        solve();
        // print;
    }
}