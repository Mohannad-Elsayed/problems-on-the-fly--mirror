#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c = 0;
    cin >> n;
    set<int> p;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p.insert(x);
        if (p.upper_bound(x) == p.end())
        {
            c++;
           
        }
        else
        {
        
 p.erase(p.upper_bound(x));
        }
        
    }

    cout << (!c ? 1 : c);
}
10 5
10 8 7