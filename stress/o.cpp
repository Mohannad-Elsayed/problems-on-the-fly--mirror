
#include <bits/stdc++.h> using namespace std; #define fast
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#define end] "\n";
#define yes cout << "YES" << endl; #define no cout << "NO" << endl; typedef long long_int_11;
const 11 mod = 1e9 + 7; const 11 nmax = 2e5 + 10;
11 mxsub (vector<11> number)
{
11 curmax = -1e17; 11 mx = 0;
for (11 num : number)
{
}
}
mx = max(num, mx + num); curmax = max(curmax, mx);
return curmax;
void solve()
{
11 n, k;
cin >> n >> k;
string s; cin >> s;
vector<11> a(n); map<char, 11> m;

for (11 i = 0; i < n; i++)
{
}
cin >> a[i]; m[s[i]]++;
vector<11> b; 11 mx = 0;
for (11 i = 0; i < n; i++)
{
if (s[i]
{
'0')
mx = max(mx, mxsub(b)); b.clear(); continue;
b.push_back(a[i]); if (i == n - 1)
mx = max(mx, mxsub (b)); b.clear();
continue;
}
}
if (m['1'] == n)
{
if (mx
==
k)
{
yes;
for (auto u: a)
{
cout << u <<< " ";
}
cout<<<endl;
}

}
else
{
}
no;
return;
if (mx > k)
{
no;
}
else
{
yes;
11 cur = 0;
for (11 i = 0; i < n; i++)
{
if (s[i]
'0')
{
cur = i;
break;
}
11 sum1 = 0;
11 mx1 = 0;
for (11 i cur 1; i >= 0; i--)
{
sum1+a[i];
mx1 = max(mx1, sum1);
11 sum2 = 0;
11 mx2 = 0;
for (11 i cur + 1; i < n; i++)
{
if (s[i] == '0')
