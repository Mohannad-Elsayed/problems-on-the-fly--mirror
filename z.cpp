// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if __has_include("cleanup/debug.h") && (!defined(ONLINE_JUDGE))
    #include "cleanup/debug.h"
#else
    #pragma message("debug.h not found, or ONLINE_JUDGE defined.")
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnglr(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
int main() {
    int ansa = rnglr(1, (1<<30)-1);
    int ansb = rnglr(1, (1<<30)-1);
    ansb = ansa;
    print(ansa);
    print(ansb);
    auto ask = [&](int a, int b) {
        if ((a^ansa) > (b^ansb)) 
            return 1;
        if ((a^ansa) == (b^ansb)) 
            return 0;
        if ((a^ansa) < (b^ansb)) 
            return -1;
    };
    int a = 0, b = 0, eq = !ask(0, 0);
    print(eq);
    if (eq) {
        for (int i = 29; ~i; i--) {
            int q1 = ask(a, (1<<i)^b);
            int q2 = ask((1<<i)^a, b);
            print(q1, q2);
            print(a, b);
            if (q1 == -1 && q2 == 1) {
                a |= (1 << i);
                b |= (1 << i);
            }
        }
        for (int i = 29; ~i; i--)
            a ^= (1 << i);
    }
    
    print(ansa, ansb);
    cout << a << ' ' << a << endl;
    cout.flush();
    return 0;
}

/*

 10001001100011111001001100011
101110110011100000110110011100


*/