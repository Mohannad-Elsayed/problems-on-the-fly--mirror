#include<bits/stdc++.h>
using namespace std;
int c=0;

int bt(int n, string a,int v){
if(v!=0) a+=to_string(v);

if (v!=0)if(stoi(a)>n) return c;

if(v!=0)c++;

 
bt(n,a,4);
bt(n,a,7);
return c;




}




int main ()
{
int n;
cin >> n;
string a;

cout << bt(n,a,0)<< endl;




}