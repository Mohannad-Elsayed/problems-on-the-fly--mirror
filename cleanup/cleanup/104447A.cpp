    // بسم الله الرحمن الرحيم

    #pragma GCC optimize("O2,unroll-loops,fast-math")
    #include <bits/stdc++.h>
    using namespace std;
    #define forr(i, st, end) for (size_t i = st; i < end; i++)
    #define int long long
    int __ceil (int m, int a) { return (m + a - 1) / a; }


    map<int, int> mp;

    void pf (int n) {
        for (int i=2; i*i<=n ;i++) {
            while (n%i == 0) {
                mp[i] ++;
                n /= i;
            }
        }
        if (n != 1) mp[n] ++;
    }

    int gcdArray(vector<int> arr) {
        int result = 0;
        forr (i, 0, arr.size()) {
            result = __gcd(result, arr[i]);
            if (result == 1) return 1;
        }
        return result;
    }
    
    inline void solve() {
        int n; cin >> n;
        vector<int> freq;
        {
            // pf (divisors of n)
            for (int i = 1; i*i <= n; i++) {
                if (n%i==0) {
                    pf (i);
                    if (i != n/i)
                        pf(n/i);
                }
            }

        }
        for (auto i: mp) {
            freq.push_back(i.second);
            // cout << i.first << ' ' << i.second << '\n';
        }
        int b=1;
        int gcdd = gcdArray(freq);
        for (auto i: mp) {
            b *= pow(i.first, (i.second / gcdd));
        }
        cout << b << ' ' << gcdd;
    }

    signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);
        int __t = 1;
    //    cin >> __t;
        while (__t--) {
            solve();
            cout << '\n';
        }
    }