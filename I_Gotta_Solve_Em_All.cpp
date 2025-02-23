#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    int n,m;
    cin>>n;
    cin>>m;
    long long ouda[n];
    long long gom3a[m];

    for(int i = 0; i < n; i++)
    {
        cin>>ouda[i];
    }
    for(int i=0; i < m;i++)
    {
        cin>>gom3a[i];
    }
    set<long long> o(ouda, ouda+n);
    set<long long> g(gom3a, gom3a+m);

    int s1 = o.size();
    int s2 = g.size();

    long long arr1[s1];
    long long arr2[s2];

    int i =0;
    for(long long val: o)
    {
        arr1[i] = val;
        i++;
    }
    i=0;
    for(long long val: g)
    {
        arr2[i] = val;
        i++;
    }
    int x = s1;
    int y = s2;

    i = 0;
    while(i < s1)
    {
        int l = 0, r = s2-1, mid;
        while(l<= r)
        {
            mid = (l+r)/2;
            if(arr2[mid] == arr1[i])
            {
                x--;
                y--;
                break;
            }
            else if ( arr2[mid] < arr1[i])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        i++;
    }
    cout<<min(x,y)<<endl;
}