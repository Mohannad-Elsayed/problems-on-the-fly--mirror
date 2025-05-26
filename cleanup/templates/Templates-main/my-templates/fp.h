ll fp(ll b, ll n, ll MOD = 1ll<<62) {
    b %= MOD;
    ll s = 1;
    while (n) {
        if (n & 1) s = s * b % MOD;
        b = b * b % MOD;
        n >>= 1;
    }
    return s;
}