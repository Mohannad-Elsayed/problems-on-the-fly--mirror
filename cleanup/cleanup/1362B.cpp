#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];  // Two children for binary representation (0 or 1)
    int count;  // Number of elements in this branch
    TrieNode() : child{nullptr, nullptr}, count(0) {}
};

class BinaryTrie {
public:
    TrieNode* root;

    BinaryTrie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 16; i >= 0; --i) {  // 17-bit numbers (since ai < 10^5)
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
            node->count++;
        }
    }

    bool find(int num) {
        TrieNode* node = root;
        for (int i = 16; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                return false;
            node = node->child[bit];
        }
        return true;
    }

    int find_min_valid_k(vector<int>& S) {
        for (int k = 1; k <= 100000; ++k) {  // Try smallest k
            bool valid = true;
            for (int s : S) {
                if (!find(s ^ k)) {
                    valid = false;
                    break;
                }
            }
            if (valid) return k;
        }
        return -1;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> S(n);
    BinaryTrie trie;

    for (int i = 0; i < n; ++i) {
        cin >> S[i];
        trie.insert(S[i]);
    }

    cout << trie.find_min_valid_k(S) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
