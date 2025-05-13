template<typename T>
class sparse {
private:
    int Log, n;
    vector<vector<T>> table;
    function<T(T, T)> merge;
    int is_overlap;

public:
    template<typename U>
    explicit sparse(vector<T> arr, U& f, int is_overlap = 0, T skip) 
        :is_overlap(is_overlap), n((int)arr.size()), merge(f), Log(__lg(arr.size()) + 1), table(Log, vector<T>(n)) {
        table[0] = arr;
        for (int l = 1; l < Log; l++) {
            for (int i = 0; i + (1 << (l - 1)) < n; i++) {
                table[l][i] = merge(table[l - 1][i], table[l - 1][i + (1 << (l - 1))]);
            }
        }
    }

    T query_overlap(int l, int r) { // [l, r], 0-based
        assert(l <= r);
        int len = __lg(r - l + 1);
        return merge(table[len][l], table[len][r - (1 << len) + 1]);
    }

    T query_non_overlap(int l, int r) { // [l, r], 0-based
        assert(l <= r);
        int sz = r - l + 1;
        T ret = skip;
        for (int i = 0; i < Log; i++) {
            if ((sz >> i) & 1) {
                ret = merge(ret, table[i][l]);
                l += (1 << i);
            }
        }
        return ret;
    }

    T query(int l, int r) {
        if (is_overlap) {
            return query_overlap(l, r);
        } else {
            return query_non_overlap(l, r);
        }
    }
};