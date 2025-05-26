// Trie for [A-Z][a-z], with countStartsWith
struct Trie {
    struct Node {
        Node* nxt[52]{};
        bool end = 0;
    } *root = new Node();

    int idx(char c) { return isupper(c) ? c - 'A' : c - 'a' + 26; }

    void insert(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int x = idx(c);
            if (!cur->nxt[x]) cur->nxt[x] = new Node();
            cur = cur->nxt[x];
        }
        cur->end = 1;
    }
    bool search(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int x = idx(c);
            if (!cur->nxt[x]) return 0;
            cur = cur->nxt[x];
        }
        return cur->end;
    }
    bool startsWith(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int x = idx(c);
            if (!cur->nxt[x]) return 0;
            cur = cur->nxt[x];
        }
        return 1;
    }
    int countStartsWith(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int x = idx(c);
            if (!cur->nxt[x]) return 0;
            cur = cur->nxt[x];
        }
        return count(cur);
    }
    int count(Node* node) {
        if (!node) return 0;
        int res = node->end;
        for (auto nxt : node->nxt) res += count(nxt);
        return res;
    }
};