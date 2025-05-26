#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

using namespace std;
template <typename T> T nxt();
template <typename T> class is_iterable {
  public:
    template <typename U>
    static auto test(U *u) -> decltype(u->begin(), u->end(), true_type{});
    template <typename> static false_type test(...);
    static constexpr bool value =
        !is_same<T, string>::value && decltype(test<T>(nullptr))::value;
};
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x);
template <typename T>
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x);
template <typename T1, typename T2> void nxtseq(pair<T1, T2> &p);
template <typename Itr> void nxtseq(Itr begin, Itr end);

using ld = long double;
using ll = long long;
using llu = unsigned long long;

const bool T = 1;         // Multiple test cases?
const string iofile = ""; // I/O file?

vector<char> decode({'\0', 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'});
unordered_map<char, int> encode({{'A', 1},
                                 {'H', 2},
                                 {'I', 3},
                                 {'M', 4},
                                 {'O', 5},
                                 {'T', 6},
                                 {'U', 7},
                                 {'V', 8},
                                 {'W', 9},
                                 {'X', 10},
                                 {'Y', 11}});

vector<int> smallCase(ll k, string str) {
    vector<int> res;
    ll pos = 0, mul = 1, len = str.size();
    reverse(all(str));
    for (char c : str) {
        pos += (encode[c] - 1) * mul;
        mul *= 11;
    }
    while (mul - pos <= k) {
        k -= mul - pos, mul *= 11, len++, pos = 0;
    }
    k += pos;
    for (int i = 0; i < len; i++) {
        mul /= 11;
        ll cnt = k / mul;
        k -= mul * cnt;
        res.push_back(cnt + 1);
    }
    return res;
}
vector<int> largeCase(ll k, string str) {
    ll len = str.size() + 1;
    vector<int> smallRes = smallCase(k, string(str.end() - 11, str.end()));
    vector<int> res(len, 0);
    for (int i = 1; i < len; i++) {
        res[i] = encode[str[i - 1]];
    }
    if (smallRes.size() == 11) {
        for (int i = 0; i < 11; i++) {
            res[res.size() - 11 + i] = smallRes[i];
        }
    } else {
        for (int i = 1; i <= 11; i++) {
            res[res.size() - 11 + i - 1] = smallRes[i];
        }
        res[len - 12] += smallRes[0];
        for (int i = len - 12; res[i] > 11; i--) {
            res[i] -= 11;
            res[i - 1]++;
        }
    }
    return res;
}
void solve() {
    int k;
    string str;
    cin >> k >> str;
    vector<int> res = str.size() > 11 ? largeCase(k, str) : smallCase(k, str);
    for (int i = 0; i < res.size(); i++) {
        cout << decode[res[i]];
    }
}

void precompute() {
}

void IOSetter();
void TCGetter();

int main() { // Don't touch it, compile with "_DEBUG" flag
    precompute();
    IOSetter();
    TCGetter();
}

void TCGetter() {
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << '\n');
};

void IOSetter() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifdef _DEBUG
//     freopen("../templates/default.in", "r", stdin);
//     freopen("../templates/default.out", "w", stdout);
// #else
//     if (iofile != "") {
//         freopen((iofile + ".in").c_str(), "r", stdin);
//         freopen((iofile + ".out").c_str(), "w", stdout);
//     }
// #endif
}

template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
template <typename T>
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x) {
    cin >> x;
}
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x) {
    for (auto &v : x) {
        nxtseq(v);
    }
}
template <typename Itr> void nxtseq(Itr begin, Itr end) {
    for (Itr itr = begin; itr < end; ++itr) {
        nxtseq(*itr);
    }
}
template <typename T1, typename T2> void nxtseq(pair<T1, T2> &p) {
    nxtseq(p.first);
    nxtseq(p.second);
}
