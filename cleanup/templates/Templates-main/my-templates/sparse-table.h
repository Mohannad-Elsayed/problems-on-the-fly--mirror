template<typename T>
struct sparse_table {
    vector<vector<T>> st;
    int n, logn;
    function<T(T, T)> merge;
    T skip;
    sparse_table(const vector<T>& a, function<T(T, T)> f, T skip = T())
        : n(a.size()), merge(f), skip(skip) {
        logn = 32 - __builtin_clz(n);
        st.assign(logn, vector<T>(n));
        st[0] = a;
        for (int k = 1; k < logn; ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                st[k][i] = merge(st[k-1][i], st[k-1][i + (1 << (k-1))]);
    }
    T query(int l, int r) { // [l, r]
        int k = 31 - __builtin_clz(r - l + 1);
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }
    T query_nonid(int l, int r) {
        T res = skip;
        for (int k = logn-1; k >= 0; --k)
            if ((1 << k) <= r - l + 1)
                res = merge(res, st[k][l]), l += 1 << k;
        return res;
    }
};