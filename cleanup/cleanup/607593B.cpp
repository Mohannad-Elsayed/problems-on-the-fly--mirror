#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Build smallest‐prime‐factor (SPF) sieve up to maxA in O(A log log A)
vector<int> build_spf(int maxA) {
    vector<int> spf(maxA+1);
    for (int i = 2; i <= maxA; ++i) {
        if (spf[i] == 0) {
            for (ll j = i; j <= maxA; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    return spf;
}

// Factor x into its distinct prime divisors using SPF in O(log x)
vector<int> factor_primes(int x, const vector<int>& spf) {
    vector<int> ps;
    while (x > 1) {
        int p = spf[x];
        ps.push_back(p);
        while (x % p == 0) x /= p;
    }
    return ps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {

        int n;
        cin >> n;

        // Read personality numbers
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Read genders as a string of length n: 'M' or 'F'
        // (Adjust this if your input format differs.)
        string gender, s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            gender.push_back(s.front());
        }
        

        // Precompute SPF up to max(a_i)
        int maxA = *max_element(a.begin(), a.end());
        auto spf = build_spf(maxA);

        // For each prime p, store at most two student indices divisible by p
        unordered_map<int, pair<int,int>> by_prime;
        by_prime.reserve(n * 2);

        // Adjacency: from each male index to list of female indices
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; ++i) {
            auto primes = factor_primes(a[i], spf);
            for (int p : primes) {
                auto &entry = by_prime[p];
                if (entry.first == 0 && entry.second == 0) {
                    // store i+1 in .first (we offset by +1 to use 0 as "empty")
                    entry.first = i+1;
                }
                else if (entry.second == 0) {
                    // second slot
                    entry.second = i+1;
                    int u = entry.first - 1;
                    int v = entry.second - 1;
                    // if they are opposite genders, add a bipartite edge
                    if (gender[u] != gender[v]) {
                        if (gender[u] == 'M')
                            adj[u].push_back(v);
                        else
                            adj[v].push_back(u);
                    }
                }
                // if both slots filled, we skip: no third student per prime
            }
        }

        // Bipartite matching: matchF[v] = u means female v is matched to male u
        vector<int> matchF(n, -1);
        vector<char> seen;

        // Try to find augmenting path from male u
        function<bool(int)> dfs = [&](int u) {
            for (int v : adj[u]) {
                if (seen[v]) continue;
                seen[v] = 1;
                if (matchF[v] == -1 || dfs(matchF[v])) {
                    matchF[v] = u;
                    return true;
                }
            }
            return false;
        };

        // Run matching
        int matches = 0;
        for (int u = 0; u < n; ++u) {
            if (gender[u] != 'M') continue;
            seen.assign(n, 0);
            if (dfs(u)) ++matches;
        }

        // Minimum number of groups = total students - number of pairs
        int answer = n - matches;
        cout << answer << "\n";
    }

    return 0;
}
