#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define ll long long
#define rep(i,n) for (i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define newline (cout << "\n")
#define println(x) (cout << #x << " : " << (x) << "\n")
#define sqrt sqrtl
 
#ifdef LOCAL_MACHINE
    template <class K, class V> ostream& operator<< (ostream& s, const pair <K, V> &p) {
        auto [x, y] = p; s << '(' << x << ", " << y << ")"; return s;
    }
    template <class T, class=typename T::value_type, class=typename enable_if<!is_same<T, string>::value && !is_same<T, complex <typename T::value_type>>::value>::type> ostream& operator<< (ostream &out, const T&v) {
        stringstream t; t << '['; for(auto &x: v) {t << x << ", ";}  
        string s = t.str(); if(!v.empty()) {s.pop_back(); s.pop_back();} s += ']'; 
        out << s; return out;
    }
    template <class T> void __prnt(T x) {cerr << x << endl;}
    void __prnt() {cerr << endl;}
    template <class T, class...Ts> void __prnt (T&&a, Ts&&...etc) {cerr << a << ", ", __prnt(etc...);}
    #define print(...) if(#__VA_ARGS__ == "") __prnt(); else (cerr << #__VA_ARGS__ <<" = ", __prnt(__VA_ARGS__))
#else
    #define print(...) 4224224
#endif
vector<int> primes;
void SieveOfEratosthenes(int n)
{
    // bool prime[n + 1];
    vector<bool> prime(n+1, 1);
    // memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}
 
bool isPowerOfTwo (int x){return x && (!(x&(x-1)));}
 
int countSetBits(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}
 
bool isPrime(int n){
    if (n <= 1)return false;
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0)return false;
    }
    return true;
}
 
int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
}
 
void sorts(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}
 
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    if (visited[node]) return;
    visited[node] = true;
    for (int neighbor : graph[node]) {
        dfs(neighbor, graph, visited);
    }
}
 
void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
 
class StringHash {
public:
    vector<int> ps1, ps2, ps3;
    int Q1 = 271, Q2 = 277, Q3 = 281;
    int M1 = 1000000007, M2 = 998244353, M3 = 1000000009;
    
    StringHash(string s) {
        int n = s.size();
        ps1 = vector<int>(n + 1);
        ps2 = vector<int>(n + 1);
        ps3 = vector<int>(n + 1);
        
        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] + 1;
            ps1[i] = ((Q1 * ps1[i - 1]) + c) % M1;
            ps2[i] = ((Q2 * ps2[i - 1]) + c) % M2;
            ps3[i] = ((Q3 * ps3[i - 1]) + c) % M3;
        }
    }
    
    int powxy(int x, int y, int M) {
        if (y == 0) return 1;
        if (y % 2 == 1) return (x * powxy(x, y - 1, M)) % M;
        int t = powxy(x, y / 2, M);
        return (t * t) % M;
    }
    
    int substrHash1(int firstIndex, int lastIndex) {
        int rem = (powxy(Q1, lastIndex - firstIndex + 1, M1) * ps1[firstIndex]) % M1;
        return (ps1[lastIndex + 1] - rem + M1) % M1;
    }
    
    int substrHash2(int firstIndex, int lastIndex) {
        int rem = (powxy(Q2, lastIndex - firstIndex + 1, M2) * ps2[firstIndex]) % M2;
        return (ps2[lastIndex + 1] - rem + M2) % M2;
    }
    
    int substrHash3(int firstIndex, int lastIndex) {
        int rem = (powxy(Q3, lastIndex - firstIndex + 1, M3) * ps3[firstIndex]) % M3;
        return (ps3[lastIndex + 1] - rem + M3) % M3;
    }
    
    vector<int> substrHash(int firstIndex, int lastIndex) {
        return {substrHash1(firstIndex, lastIndex), substrHash2(firstIndex, lastIndex), substrHash3(firstIndex, lastIndex)};
    }
};
 
template <typename SourceContainer, typename DestinationContainer>
void copyElements(const SourceContainer& source, DestinationContainer& destination) {
    destination.clear();
    destination.reserve(source.size()); // Optional, reserve space for better performance
 
    std::copy(std::begin(source), std::end(source), std::back_inserter(destination));
}
template<typename T>
void printElements(const T& container) {
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}
template<typename T>
void takeInput(T& container, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> container[i];
    }
}
 
 
void run()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
}
int cnt;
int findpos(int val,int n){
    int l = -1, r = n+1;
    while(r-l>1){
        cnt++;
        int m = (r+l)/2;
        // print(l,m,r);
        if(primes[m]<=val){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l+1;
}
 
void solve(int n) {
    // int n;
    // cin>>n;
    int count = 0;
    for(int i=1;i<=n/2;i++){
        count += findpos(n/i,n);
    }
    // cout<<count<<endl;
}

int mx, nnn;
signed main() {
    SieveOfEratosthenes(100000001);
    for (int n = 1; n <= 10000; n++) {
        cnt = 0;
        solve(n);
        if (cnt > mx) {
            mx = cnt;
            nnn = n;
        }
    }
    cout << cnt << '\n' << nnn;
    return 0;
}
// 99963060