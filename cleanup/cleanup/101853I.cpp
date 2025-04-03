#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl '\n'
#define GM_AMR     ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(x) (int)x.size()
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define debug4(a, b, c, d) cerr << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << endl;
#define debug5(a, b, c, d, e) cerr << #a << " = " << a << ", " << #b <<
#define debug6(a, b, c, d, e, f) cerr << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << endl;
#define bit(x, i) ((x) >> (i) & 1)
#define setbit(x, i) ((x) |= (1 << (i)))
#define clrbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define on(mask, i) (mask | (1 << i))
#define off(mask, i) (mask & ~(1 << i))
#define check(mask, i) (mask & (1 << i))
#define allOnes(mask) (~mask & ((1 << n) - 1))
#define leftmostBit(mask) (mask & -mask)
#define rightmostBit(mask) ((mask & -mask) + mask)
#define bitPosition(mask, i) (log2(mask & (1 << i)))
#define bitCount(mask) __builtin_popcount(mask)
#define reverseBits(mask) __builtin_rev(mask)
#define parity(mask) __builtin_parity(mask)
#define ceilDiv(x, y) (x + y - 1) / y
#define floorDiv(x, y ) __builtin_floor(x) / y
#define isPrime(x) (x <= 1? false : (x == 2? true : (x % 2 == 0? false : __is_prime(x))))
#define isPerfectSquare(x) (sqrt(x) * sqrt(x) == x)
#define sqr(x) ((x)*(x))
#define dist(x1, y1, x2, y2) sqrt(sqr(x1 - x2) + sqr(y1 - y2))
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) (x * y) / gcd(x, y)
#define eulerPhi(n) (n == 1? 1 : n * (1 - 1.0 / n) * eulerPhi(n - 1))
#define isPerfectSquare(x) (sqrt(x) * sqrt(x) == x)
#define isFibonacci(x) (fibonacci.find(x)!= fibonacci.end())
#define fibonacci {0, 1, 1};
#define prime {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}
#define sqr(x) ((x)*(x))
#define dist(x1, y1, x2, y2) sqrt(sqr(x1 - x2) + sqr(y1 - y2))
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) (x * y) / gcd(x, y)
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const double EPS = 1e-9;
#define inf 0x3f3f3f3f
#define PI 3.14159265358979323846
ll sum( ll a , ll b){
    return ((a%MOD) + (b%MOD)) %MOD ;
}
ll sub( ll a , ll b){
    return ((a%MOD) - (b%MOD)) %MOD;
}
ll mul( ll a , ll b){
    return ((a % MOD) * (b % MOD) % MOD);
}
ll POW( ll a , ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int opn[] = {'[', '(', '{'};
int cls[] = {']', ')', '}'};
int Hk[] = {2, 2, -2, -2, 1, 1, -1, -1};
int Hy[] = {1, -1, 1, -1, 2, -2, 2, -2};
//    j
int Dj[] = {1,  0, -1,   0,   1,  1, -1, -1};
int Di[] = {0,  1,  0,  -1,   1, -1,  1, -1};
//   i
char D[] ={'R', 'D','L','U'};

// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.
template<class T> using ordered_set = tree<T, null_type, less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;




void solve() {
    int a , b , d;
    cin >> a >> b >> d;
    long double side = sqrtl((1LL*d * d) /2.0);
    // cout << side << endl;
    long double arr = PI * (d/2.0) * (d/2.0);
    long double arr2 = arr - (side*side);
    // area smaller circle * 2 - arr2
    long double area_smaller = (side/2) * (side/2) * PI;
    area_smaller *= 2;
    cout << area_smaller - arr2 << '\n';
    // cout << arr << endl <<(side*side) <<endl<< arr2 << endl;
    // cout << arr2 - (PI * (side/4.0) * (side/4.0))/2.0 << endl;
    // cout << (side*side) << endl;
}



int main(){
    cout << fixed << setprecision(12);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}