#include <bits/stdc++.h>
using namespace std;

int b1 = 31, b2 = 69, MODHASH = 1e9 + 7;
vector<int> Pb1, Pb2;

void pre(int maxSize) {
    Pb1 = Pb2 = vector<int>(++maxSize);
    Pb1[0] = 1, Pb2[0] = 1;
    for (int i = 1; i < maxSize; i++) {
        Pb1[i] = int(1LL * Pb1[i - 1] * b1 % MODHASH);
        Pb2[i] = int(1LL * Pb2[i - 1] * b2 % MODHASH);
    }
}

struct Hash {
    pair<int, int> code;
    int size;
    explicit Hash(pair<int, int> x = {}, int sz = {}) : code(std::move(x)), size(sz) { }

    Hash(int x) : code({x % MODHASH, x % MODHASH}), size(1) { }

    Hash(const string &x) : code(), size(0) {
        for(char c : x) *this = *(this) + c;
    }

    friend Hash operator+(const Hash &f, const Hash &o) {
        return Hash({int((1LL * f.code.first * Pb1[o.size] + o.code.first) % MODHASH),
                     int((1LL * f.code.second * Pb2[o.size] + o.code.second) % MODHASH)}
                , f.size + o.size);
    }

    bool operator==(const Hash &o) const {
        return size == o.size && code == o.code;
    }
};

struct HashRange {
    vector<Hash> p, s;
    HashRange(const string &t) : p(t.size()), s(t.size()) {
        p.front() = t.front();
        for(int i = 1; i < t.size(); i++) {
            p[i] = p[i - 1] + t[i];
        }
        s.back() = t.back();
        for(int i = int(t.size()) - 2; i >= 0; i--) {
            s[i] = s[i + 1] + t[i];
        }
    }
    Hash get(int l, int r) { // zero-based
        if(l > r) return Hash();
        if(!l) return p[r];
        return Hash({(p[r].code.first - p[l - 1].code.first * 1LL * Pb1[r - l + 1] % MODHASH + MODHASH) % MODHASH,
                     (p[r].code.second - p[l - 1].code.second * 1LL * Pb2[r - l + 1] % MODHASH + MODHASH) % MODHASH}
                , r - l + 1);
    }
    Hash inv(int l, int r) { // zero-based
        if(l > r) return Hash();
        if(r + 1 == s.size()) return s[l];
        return Hash({(s[l].code.first - s[r + 1].code.first * 1LL * Pb1[r - l + 1] % MODHASH + MODHASH) % MODHASH,
                     (s[l].code.second - s[r + 1].code.second * 1LL * Pb2[r - l + 1] % MODHASH + MODHASH) % MODHASH}
                , r - l + 1);
    }
};

int main(){
    pre(1000);
    string a = "aabcdeaa", b = "edcbaaaa", c = "aabcdeaaedcbaaaa";
    HashRange h1(a), h2(b), h3(c);
    cout << h1.get(2, 5).code.first << ' ' << h1.get(2, 5).code.second << '\n' <<
        h2.inv(0, 3).code.first << ' ' << h2.inv(0, 3).code.second << '\n' << 
        (h1.get(2,5) == h2.inv(0, 3));

    cout << "\n\n";
    cout << h3.code.first << ' ' << h3.code.second << '\n'
    << (h1+h2).code.first << ' ' << (h1+h2).code.second;
    return 0;
}