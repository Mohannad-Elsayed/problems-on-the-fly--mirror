// Based on https://en.algorithmica.org/hpc/data-structures/segment-trees/
template <int N, class U, int b = 4> 
struct wide_segment_tree {
    constexpr static int B = 1 << b;
    constexpr static U Default = 0;
    U combine(U x, U y) const {
        return x+y;
    }
    struct Precalc {
        alignas(64) uint64_t mask[B][B];

        constexpr Precalc() : mask{} {
            for (int k = 0; k < B; k++)
            for (int i = 0; i < B; i++)
                mask[k][i] = (i > k ? -1 : 0);
        }
    };

    constexpr static Precalc T{};

    constexpr static int height(int n) {
        return (n < B ? 1 : height(n / B) + 1); 
    }

    constexpr static int offset(int h) {
        int s = 0, n = N;
        while (h--) {
            n = (n + B - 1) / B;
            s += n * B + B;
        }
        return s;
    }

    constexpr static int H = height(N);

    alignas(64) 
    U data[offset(H)];

    void build() {
    #pragma unroll(1024)
        for (int h = 0; h < H - 1; h++) {
            for (int i = 0; i < offset(h + 1) - offset(h) - B; i += B) {
            for (int j = 0; j < B; j++)
                data[offset(h) + i + j + 1] = 
                    combine(data[offset(h) + i + j + 1], data[offset(h) + i + j]);
            data[offset(h + 1) + (i >> b) + 1] = std::exchange(data[offset(h) + i + B], Default);
            }
        }

        for (int i = 0; i < B - 1; i++)
            data[offset(H - 1) + i + 1] += data[offset(H - 1) + i];
    }
    U query(int k) const { // 1-based
        U res = 0;
        for (int h = H - 1; h >= 0; h--) {
            int idx = offset(h) + (k >> (h * b));
            res = combine(data[idx], res);
        }
        return res;
    }
    U query(int l, int r) { // 1-based
        return query(r) - query(l-1);
    }
    void add(int k, int _x) { // 1-based
        U x = _x + U{};
        for (int h = H - 1; h >= 0; h--) {
        int p = k >> (h * b);
        auto l = (U *)&data[offset(h) + (p & ~(B - 1))];
        auto m = (U *)T.mask[p & (B - 1)];
            for (int i = 0; i < B / 4; i++)
            l[i] += x & m[i];
        }
    }
    void set(int k, int value) { // 1-based
        int current_value = query(k) - (k > 0 ? query(k - 1) : 0);
        add(k, value - current_value);
    }

    wide_segment_tree(vector<U> &v) {
        int n = v.size();
        memset(data, Default, sizeof(data));
        for (int i = 0; i < n; i++)
            data[offset(0) + i + 1] = v[i];
        build();
    }
};