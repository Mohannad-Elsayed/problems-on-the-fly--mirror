#include<bits/stdc++.h>
using namespace std;
const int N = 1e8;
bool comp[N];
vector<int>primes;
void oldsieve()
{
    memset(comp,0,sizeof comp);
    primes.clear();
    
    bool done = false;
    for(int i=2;i<N;i++)
        if(!comp[i])
        {
            primes.push_back(i);
            
            if (i * i > N) {
            	done = true;
            }
            
            if (!done) for(int j=i*i;j<N;j+=i)
                comp[j]=1;
        }
}
void newsieve()
{
    memset(comp,0,sizeof comp);
    primes.clear();
    for(int i=2;i<N;i++)
    {
        if(!comp[i])
            primes.push_back(i);
            for(int j=0,si=primes.size();j<si&&i*primes[j]<N;j++)
            {
                comp[primes[j]*i]=1;
                if(i%primes[j]==0)break;
            }
    }
}
int main()
{
	auto t0 = clock();
    oldsieve();
    //for(int i=0;i<20;i++)cout<<primes[i]<<' ';cout<<endl;
    auto mid = clock();
    cout << "diff is " << (1.0 * (mid - t0)) / CLOCKS_PER_SEC << endl;
    newsieve();
    //for(int i=0;i<20;i++)cout<<primes[i]<<' ';cout<<endl;
    cout << "diff is " << (1.0 * (clock() - mid)) / CLOCKS_PER_SEC << endl;
}