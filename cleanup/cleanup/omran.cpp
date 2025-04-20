#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef deque<ll> dqll;
typedef vector<char> vc;
typedef vector <pair <ll, ll>> vpll;
typedef stack<char> stc;
typedef stack<ll> stll;
typedef pair<ll, ll> pll;
typedef set<ll> sll;
typedef set<ll, greater<ll>> reversesll;
typedef multiset<ll> msll;
typedef multiset<ll, greater<ll>> reversemsll;
typedef unordered_map<ll, ll> umll;
typedef unordered_set<ll> usll;
#define OMRAN {ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);}
#define is_string_in(s1, s2) s1.find(s2) != string::npos

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
ll MOD = 1e9 + 7;
ll MAX = 1e6;
// Seive 3alsari3 mno
//-----------------------------------------------------
vector<bool> p(MAX + 1, 1);
map<ll, ll> primes;
void seive(){
    p[0] = p[1] = false;
    for(ll i = 2; i <= MAX; i++){
        if(p[i]){
            primes[i]++;
            for(ll j = i*i; j <= MAX; j+=i){
                p[j] = false;
            }
        }
        
    }
}
//-----------------------------------------------------
//sort with one argument
//stable_partition(all(v), [](ll a){});

vector<vector<char>> graph;
string ans, valid;
bool is_valid;
ll r, c, stx, sty, edx, edy;

void dfs(ll x, ll y, vector<vector<bool>> &visited){

    visited[x][y] = true;
    if(x == edx && y == edy){
        is_valid = true;
        if(valid.empty() || ans.size() < valid.size()){
            valid = ans;
        }
        return;
    }

    if(y + 1 < c && (graph[x][y + 1] == '.'|| graph[x][y+1] == 'B') && !visited[x][y + 1]){
        ans.push_back('R');
        dfs(x, y + 1, visited);
        ans.pop_back();
    }
    if(y - 1 >= 0 && (graph[x][y - 1] == '.'|| graph[x][y-1] == 'B') && !visited[x][y - 1]){
        ans.push_back('L');
        dfs(x, y - 1, visited);
        ans.pop_back();
    }
    if(x + 1 < r && (graph[x + 1][y] == '.'|| graph[x + 1][y] == 'B') && !visited[x + 1][y]){
        ans.push_back('D');
        dfs(x + 1, y, visited);
        ans.pop_back();
    }
    if(x - 1 >= 0 && (graph[x - 1][y] == '.'|| graph[x-1][y] == 'B') && !visited[x - 1][y]){
        ans.push_back('U');
        dfs(x - 1, y, visited);
        ans.pop_back();
    }
    visited[x][y] = false;
}

int main(){
    //freopen("file_name.extension", "rt", stdin); //input
    //freopen("file_name.extension", "wt", stdout); //output
    OMRAN
    
    ll tests;
    tests = 1;
    //cin >> tests;
    while(tests--){
        cin >> r >> c;
        valid = false;
        graph.resize(r, vc(c));
        vector<vector<bool>> visited(r, vb(c));
        for(int i = 0; i < r; i++){
            for(int j=0; j < c; j++){
                cin >> graph[i][j];
                if(graph[i][j] == 'A'){
                    stx = i; sty = j;
                }else if(graph[i][j] == 'B'){
                    edx = i; edy = j;
                }
                visited[i][j] = false;
            }
        }
        valid = "";
        dfs(stx, sty, visited);
        if(is_valid){
            YES;
            cout << valid.size() << endl;
            cout << valid << endl;
        }else NO;
    }
}