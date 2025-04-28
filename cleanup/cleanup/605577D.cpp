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
    // freopen("tree.in", "r", stdin);
}
map<string,vector<string>> m;
vector<int> barlevel(40200, 1);
int leaf=0,dir=0;
void dfs(string node,int level){
    if(m[node].size()==0)
        leaf++;
    else
        dir++;
    int n = m[node].size(),i=0;
    for(auto child : m[node]){
        forj(0,level){
            if (barlevel[j])
                cout << "|   ";
            else
                cout << "   ";
        }
        if(i==n-1){
            cout << "|__ " << child << "\n";
            barlevel[level] = 0;
        }
        else
            cout << "|-- " << child << "\n";
        dfs(child,level+1);
        i++;
    }
}

int main()
{
    // PleaseNoTL();
    Meow();
    string s,a,b;
    int n;
    cin >> s >> n;
    set<string> stea, steb, roots;
    fori(0,n){
        cin >> a >> b;
        stea.insert(a);
        steb.insert(b);
        m[a].push_back(b);
    }
    for(auto &x : m){
        sort(all(x.S));
    }
    for (auto sss : stea)
        if (!steb.count(sss))
            roots.insert(sss);
    for (auto sss : roots) {
        cout << sss << nl;
        dfs(sss, 0);
    }
    cout << nl;
    cout << dir << " directories, " << leaf << " files";
}