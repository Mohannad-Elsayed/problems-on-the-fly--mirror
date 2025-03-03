#include <iostream>
#include "bits/stdc++.h" 
using namespace std;
typedef unsigned long long ull;
#define DOMAIN_EXPANTION ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define INFINITE_VOID solve();
#define vecbe(v) v.begin(), v.end()
#define arrbe(a,s) a, a+s
#define ll long long
void loop(ll arr[], ll n) {for(ll i = 0; i < n; i++) cin >> arr[i];}
bool odd(int n) {return n%2!=0;}
bool even(int n) {return n%2==0;}
bool is_divisble(int n, int m) {return n%m==0;}
bool issqrt(int n) {int s = sqrt(n);if(s*s == n) return true;return false;}
void prefix(ll b[], ll n) {for(ll i = 1; i < n+1; i++) {b[i] += b[i-1];}}
void print(ll a[], ll n) {for(ll i = 0; i < n; i++) cout << a[i] << " ";}

void solve() {

    int q;
    deque<int>dq;
    cin >> q;
    
    int reversed = 0;
    while(q--)
    {
        
        string msg;
        int n;

        cin >> msg;
        if(msg == "toFront" || msg == "push_back")
            cin >> n;

        if(msg =="front")
        {
            if (!dq.empty())
            {
                if(reversed)
                {
                    cout << dq.back() << "\n";
                    dq.pop_back();  
                }
                else{
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
            }
            
            else cout << "No job for Ada?" << "\n";
        }
        if(msg == "back")
        {
            if (!dq.empty())
            {
                if(reversed)
                {
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back() << "\n";
                    dq.pop_back(); 
                }
                
            }

            else cout << "No job for Ada?" << "\n";
        }
        if(msg == "reverse")
        {
            if(reversed) reversed = 0;
            else reversed = 1;
        }
            
        if(msg == "toFront")
            dq.push_front(n);
        if(msg == "push_back")
            dq.push_back(n);
    }
}


int main() {
    freopen("in.in", "rt", stdin);
    freopen("out.out", "wt", stdout);
    DOMAIN_EXPANTION;
    // int t; cin >> t;
    // while(t--)
    INFINITE_VOID;
}