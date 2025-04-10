pair<Mint, Mint> fib (ll n) { // return f_n, f_n+1
    if (n == 0)
        return {Mint(0), Mint(1)};
    auto p = fib(n >> 1);
    Mint c = p.first * (2 * p.second - p.first);
    Mint d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}