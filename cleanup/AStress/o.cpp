#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n,c;
    while(cin>>n && n)
    {
        vector<int> v;
        int p = n;
        int i = 1;
        while(p--)
        {
            cin>>c;
            if(c != i)
            {
                v.push_back(c);
            }
            else
            {
                i++;
            }
        }
        int x = v.size();
        while(x--)
        {
            if(v.back() == i)
            {
                v.pop_back();
                i++;
            }
            else
            {
                break;
            }
        }
        if(v.empty())
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
}

