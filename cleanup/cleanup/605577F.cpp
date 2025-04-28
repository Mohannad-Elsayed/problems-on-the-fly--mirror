#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<iostream>
#define int long long
#define len(s) (s).size()
#define substring(s, start, length) (s).substr(start, length)
//using uint=uint64_t;
//const uint mod=999999910724017129;
double pi = 2*acos(0.0);
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
using namespace std;
using namespace __gnu_pbds;
//find_by_order(x) => return element at the given position(idx) x => takes * before it
//order_of_key(x) => return number of elements smaller than x
//if we want duplicates => we will pass pair instead of int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("random.in","r",stdin);
    int n;
    cin >> n;
    vector<int> a(n), p(n), s(n);
    for(int &i : a)
        cin >> i;
    {
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && a[st.top()] < a[i]) st.pop();
            p[i] = st.empty()? 0: st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && a[st.top()] <= a[i]) st.pop();
            s[i] = st.empty()? n - 1: st.top() - 1;
            st.push(i);
        }
    }
    int64_t ans = 0, tot = n * 1LL * (n + 1) >> 1;
    for(int i = 0; i < n; i++) {
        ans += (i - p[i] + 1LL) * a[i] * (s[i] - i + 1LL);
    }
    cout << fixed << setprecision(10);
    cout << (long double)(ans) / tot << '\n';
    return 0;
}