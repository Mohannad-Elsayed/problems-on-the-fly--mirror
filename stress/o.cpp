/***--Nemo_1--***/
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define all(n) n.begin(), n.end()
#define int int64_t
using namespace std;
int check(int x, int y, int z) {
    return (x + y > z && x + z > y && y + z > x);
}
int cnt;


bool isPowerOfTwo(long long n) {
    return (n > 0 && (n & (n - 1)) == 0);
}


bool ip(int n) {
    return (n & (n - 1)) == 0;
}

bool isValidTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}



int solve(int n)
{
    

    for (int i = 1; i < 10000; i++)
    {
        if(i>=n) break;
        int a = n;
        int b = i;
        int c = a ^ b;
        if ((a+b>c) && (a+c > b) && (b + c > a) && b<a){
            return b;
        }
    }
    return -1;
        










}


int bfsolve(int x) {
    
    if ((x & (x - 1)) == 0 || (x & (x + 1)) == 0) {
        return -1;
    }
    
    int a = std::__lg(x);
    int b = __builtin_ctz(~x);
    
    int y = x ^ (1 << a) ^ (1 << b);
    return y;
}


void upsolve()
{
    int mx = -1, mxnum;
    for (int i = 2; i < int(1e9)+1; i++) {
        int c = solve(i);
        int b = bfsolve(i);
        if (c == -1) {
            if (b != -1) {
                cout << "neg:  " << i << ' ' << c << ' ' << b << '\n';
                exit(0);
            }
        }
        else if (!check(i, c, i^c)) {
            cout << i << ' ' << c << ' ' << (i^c) << '\n';
            exit(0);
        }
        else {
            if (mx < cnt) {
                mx = cnt;
                mxnum = i;
            }
        }
    }
    cout << "i:  " << mx << ' ' << mxnum;
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
}
void NEMO();
int32_t main()
{
    NEMO();
    // solve();
    upsolve();
    return 0;
}
void NEMO()
{
    ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
}