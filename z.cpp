#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> make_evils(ll prime, ll n)
{
	vector<ll> ret(n);
	for (ll i = 0; i < n; i++)
		ret[i] = (i + 1) * prime;
	return ret;
}

void test_evils(const vector<ll>& evils)
{
    unordered_set<ll> st;

	clock_t start = clock();

	for (ll x : evils)
		st.insert(x);

	clock_t end = clock();

	cout << fixed;
	cout.precision(3);
	cout << "Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
}

int main()
{
    for (int i = 0; i<10; i++) {
        vector<ll> evils = make_evils(571, 20000);
        test_evils(evils);
    }
}