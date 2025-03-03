#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef deque<ll> dqll;
typedef vector<char> vc;
typedef vector <pair <ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef set<ll> sll;
typedef set<ll, greater<ll>> reversesll;
typedef multiset<ll> msll;
typedef multiset<ll, greater<ll>> reversemsll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll mod = 1e9 + 7;
    ll length, queries, num;
    cin >> length >> queries;
    vll v(length);
    for(int i = 0; i < length; i++) cin >> v[i], v[i]%=mod;
    ll prv = v[0];
    for(int i = 0; i < length-1; i++){
        // ll prv;
        if(i == 0){
            prv = gcd(v[i], v[i + 1]) % mod;
        }
        else {
            prv = gcd(prv, v[i+1]) % mod;
        }
    }

    for(int i = 0; i < queries; i++){
        ll op, result;
        cin >> op;
        result = (op%mod * prv%mod) %mod;
        cout << result << endl;
        prv = result;
    }

}