#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5;
int max_divisor[N + 7], a[N + 1], mem[N];
int n;
vector<int> primes[N];

void sieve() {
    for (int i = 2; i <= N; ++i) {
        if (max_divisor[i] == 0) {
            for (int j = i; j <= N; j += i)
                max_divisor[j] = i;
        }
    }
}

void get_primes(int x, vector<int> &res) {
    while (x != 1) {
        int p = max_divisor[x], cnt = 0;
        while (!(x % p))
            cnt++, x /= p;
        res.emplace_back(p);
    }
}

int dp(int i) {
    if (i == n)return 0;
    int &ret = mem[i];
    if (~ret)return ret;
    ret = 1;
    vector<int> p;
    get_primes(a[i], p);
    for (int &x: p) {
        auto it = upper_bound(primes[x].begin(), primes[x].end(), i);
        if (it != primes[x].end()) {
            ret = max(
                    ret,
                    1 + dp(*it)
            );
        }
    }
    return ret;
}


int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    sieve();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vector<int> res;
        get_primes(a[i], res);
        for (int &x: res) {
            primes[x].emplace_back(i);
        }
    }
    memset(mem, -1, sizeof mem);
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        ret = max(
                ret,
                dp(i)
        );
    }
    cout << ret;
}