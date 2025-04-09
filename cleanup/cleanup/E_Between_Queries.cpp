#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    long long arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    sort(arr,arr+n);
    while(q--)
    {
        int last =0, first =0,l = 0, r= n-1, mid1,mid2;
        long long a,b;
        cin>>a;
        cin>>b;
        while(l <= r)
        {
            mid1 = (l+r)/2;
            if (arr[mid1] < a)
            {
                l = mid1 + 1;
            }
            else
            {
                first = mid1;
                r = mid1 - 1;
            }
        }
        l = 0, r= n-1;
        while(l <=r)
        {
            mid2 = (l+r)/2;
            if(arr[mid2] > b)
            {
                r = mid2 - 1;
            }
            else
            {
                last = mid2;
                l = mid2 + 1;
            }
        }
        long long ans = last - first + 1;
        cout<<ans<<"\n";
    }
}