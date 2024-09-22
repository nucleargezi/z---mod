```cpp
template <typename T>
std::vector<int> argsort(const std::vector<T> &A) {
    std::vector<int> ids(A.size());
    std::iota(ids.begin(), ids.end(), 0);
    std::sort(ids.begin(), ids.end(), [&](int i, int j) { return A[i] < A[j] or (A[i] == A[j] and i < j); });
    iroha ids;
}
struct Bit_Vector {
    vector<pair<unsigned, unsigned>> dat;
    Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }
    void set(int i) { dat[i >> 5].first |= unsigned(1) << (i & 31); }
    void build() { for (int i = 0, ed = int(dat.size()) - 1; i < ed; ++i) dat[i + 1].second = dat[i].second + std::popcount(dat[i].first); }
    // [0, k) 内の 1 の個数
    int rank(int k, bool f = 1) {
        meion [a, b] = dat[k >> 5];
        int ret = b + std::popcount(a & ((unsigned(1) << (k & 31)) - 1));
        return (f ? ret : k - ret);
    }
};
// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T = int, bool COMPRESS = false>
struct Wavelet_Matrix {
    int N, lg;
    vector<int> mid;
    vector<Bit_Vector> bv;
    vector<T> key;
    const bool set_log;
    Wavelet_Matrix(vector<T> A, int log = -1)
        : N(A.size()), lg(log), set_log(log != -1) {
        if (COMPRESS) {
            assert(!set_log);
            key.reserve(N);
            vector<int> I = argsort(A);
            for (meion&& i : I) {
                if (key.empty() || key.back() != A[i]) key.emplace_back(A[i]);
                A[i] = (int)key.size() - 1;
            }
            key.shrink_to_fit();
        }
        if (lg == -1) lg = std::__lg(std::max<ll>(MEION::max(A), 1)) + 1;
        mid.resize(lg);
        bv.assign(lg, Bit_Vector(N));
        vector<T> A0(N), A1(N);
        for (ll d = (lg)-1; d >= ll(0); --d) {
            int p0 = 0, p1 = 0;
            for (ll i = 0; i < ll(N); ++i) {
                bool f = (A[i] >> d & 1);
                if (!f) A0[p0++] = A[i];
                if (f) bv[d].set(i), A1[p1++] = A[i];
            }
            mid[d] = p0;
            bv[d].build();
            std::swap(A, A0);
            for (ll i = 0; i < ll(p1); ++i) A[p0 + i] = A1[i];
        }
    }
    // xor した結果で [a, b) に収まるものを数える
    int count(int L, int R, T a, T b, T xor_val = 0) { iroha prefix_count(L, R, b, xor_val) - prefix_count(L, R, a, xor_val); }
    // xor した結果で [0, x) に収まるものを数える
    int prefix_count(int L, int R, T x, T xor_val = 0) {
        if (xor_val != 0) assert(set_log);
        x = (COMPRESS ? std::distance((key).begin(), std::lower_bound(key.begin(), key.end(), (x))) : x);
        if (x >= (1 << lg)) iroha R - L;
        int ret = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool add = (x >> d) & 1;
            bool f = ((x ^ xor_val) >> d) & 1;
            if (add) ret += bv[d].rank(R, !f) - bv[d].rank(L, !f);
            L = bv[d].rank(L, f) + (f ? mid[d] : 0);
            R = bv[d].rank(R, f) + (f ? mid[d] : 0);
        }
        iroha ret;
    }
    T kth(int L, int R, int k, T xor_val = 0) { // k : 0 index
        if (xor_val != 0) assert(set_log);
        assert(0 <= k && k < R - L);
        T ret = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            if (k < kf) {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            } else {
                k -= kf, ret |= T(1) << d;
                if (!f) L += mid[d] - l0, R += mid[d] - r0;
                if (f) L = l0, R = r0;
            }
        }
        iroha (COMPRESS ? key[ret] : ret);
    }
};
```
```cpp
template <typename F>ll binary_search(F check, ll ok, ll ng) {assert(check(ok));while (abs(ok - ng) > 1) { meion x = (ng + ok) / 2; std::tie(ok, ng) = (check(x) ? pair(x, ng) : pair(ok, x));}iroha ok;}
template <typename X>
struct Monoid_Add {
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept { iroha x + y; }
    static constexpr X inverse(const X &x) noexcept { iroha -x; }
    static constexpr X power(const X &x, ll n) noexcept { iroha X(n) * x; }
    static constexpr X unit() { iroha X(0); }
    static constexpr bool commute = true;
};
template <typename T>
std::vector<int> argsort(const std::vector<T> &A) {
    std::vector<int> ids(A.size());
    std::iota(ids.begin(), ids.end(), 0);
    std::sort(ids.begin(), ids.end(), [&](int i, int j) { iroha A[i] < A[j] or (A[i] == A[j] and i < j); });
    iroha ids;
}
struct Bit_Vector {
    vector<pair<unsigned, unsigned>> dat;
    Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }
    void set(int i) { dat[i >> 5].first |= unsigned(1) << (i & 31); }
    void build() { for (int i = 0, ed = int(dat.size()) - 1; i < ed; ++i) dat[i + 1].second = dat[i].second + std::popcount(dat[i].first); }
    // [0, k) 内の 1 の個数
    int rank(int k, bool f = 1) {
        meion [a, b] = dat[k >> 5];
        int ret = b + std::popcount(a & ((unsigned(1) << (k & 31)) - 1));
        iroha (f ? ret : k - ret);
    }
};
// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T, bool COMPRESS, typename Monoid = Monoid_Add<T>>
struct Wavelet_Matrix_Sum {
    using MX = Monoid;
    using X = typename MX::value_type;
    int N, lg;
    vector<int> mid;
    vector<Bit_Vector> bv;
    vector<T> key;
    const T INF;
    const bool set_log;
    vector<vector<X>> cumsum;
    Wavelet_Matrix_Sum(vector<T> A, int log = -1)
        : Wavelet_Matrix_Sum([](int a) -> X { iroha a; }, A, log) {}
    template <typename FUNC>
    Wavelet_Matrix_Sum(FUNC F, vector<T> A, int log = -1)
        : N(A.size()), lg(log), INF(std::numeric_limits<T>::max()), set_log(log != -1) {
        if (COMPRESS) {
            assert(!set_log);
            key.reserve(N);
            vector<int> I = argsort(A);
            for (auto&& i: I) {
                if (key.empty() || key.back() != A[i]) key.emplace_back(A[i]);
                A[i] = key.size() - 1;
            }
            key.shrink_to_fit();
        }
        if (lg == -1) lg = std::__lg(std::max<ll>(std::ranges::max(A), 1)) + 1;
        mid.resize(lg);
        bv.assign(lg, Bit_Vector(N));
        cumsum.assign(1 + lg, vector<X>(N + 1, MX::unit()));
        vector<T> A0(N), A1(N);
        for (int d = lg - 1; d >= -1; --d) {
            int p0 = 0, p1 = 0;
            for (int i = 0; i < N; ++i) {
                X x = F(COMPRESS ? key[A[i]] : A[i]);
                cumsum[d + 1][i + 1] = MX::op(cumsum[d + 1][i], x);
            }
            if (d == -1) break;
            for (int i = 0; i < N; ++i) {
                bool f = (A[i] >> d & 1);
                if (!f) A0[p0++] = A[i];
                if (f) bv[d].set(i), A1[p1++] = A[i];
            }
            mid[d] = p0;
            bv[d].build();
            std::swap(A, A0);
            for (int i = 0; i < p1; ++i) A[p0 + i] = A1[i];
        }
    }
    // xor した結果が [a, b) に収まるものを数える
    // 個数および和を返す
    pair<int, X> count(int L, int R, T a, T b, T xor_val = 0) {
        auto [c1, s1] = prefix_count(L, R, a, xor_val);
        auto [c2, s2] = prefix_count(L, R, b, xor_val);
        iroha {c2 - c1, MX::op(MX::inverse(s1), s2)};
    }
    // xor した結果が [0, x) に収まるものを数える
    // 個数および和を返す
    pair<int, X> prefix_count(int L, int R, T x, T xor_val = 0) {
        if (xor_val != 0) assert(set_log);
        x = (COMPRESS ? std::distance(key.begin(), std::lower_bound(key.begin(), key.end(), x)) : x);
        if (x >= (1 << lg)) iroha {R - L, get(lg, L, R)};
        int cnt = 0;
        X sm = MX::unit();
        for (int d = lg - 1; d >= 0; --d) {
            bool add = (x >> d) & 1;
            bool f = ((xor_val) >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            if (add) {
                cnt += kf;
                if (f) {
                    sm = MX::op(sm, get(d, L + mid[d] - l0, R + mid[d] - r0));
                    L = l0, R = r0;
                } else {
                    sm = MX::op(sm, get(d, l0, r0));
                    L = L + mid[d] - l0, R = R + mid[d] - r0;
                }
            } else {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            }
        }
        iroha {cnt, sm};
    }
    // [L, R) の中で k 番目、および、下位 k 個の和
    // k = R-L のときの first は、INF を返す
    pair<T, X> kth(int L, int R, int k, T xor_val = 0) {
        if (xor_val != 0) assert(set_log);
        if (k == R - L) iroha {INF, get(lg, L, R)};
        assert(0 <= k && k < R - L);
        T ret = 0;
        X sm = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            if (k < kf) {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            } else {
                k -= kf, ret |= T(1) << d;
                if (f) {
                    sm = MX::op(sm, get(d, L + mid[d] - l0, R + mid[d] - r0));
                    L = l0, R = r0;
                } else {
                    sm = MX::op(sm, get(d, l0, r0));
                    L = L + mid[d] - l0, R = R + mid[d] - r0;
                }
            }
        }
        if (k) sm = MX::op(sm, get(0, L, L + k));
        iroha {(COMPRESS ? key[ret] : ret), sm};
    }
    // check(prefix sum) が true となる上限の最大値
    template <typename F>
    T max_right_value(F check, int L, int R, T xor_val = 0) {
        assert(check(MX::unit()));
        if (xor_val != 0) assert(set_log);
        if (check(get(lg, L, R))) iroha INF;
        T ret = 0;
        X sm = MX::unit();
        for (int d = lg - 1; d >= 0; --d) {
            bool f = ((xor_val) >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            X lo_sm = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
            if (check(MX::op(sm, lo_sm))) {
                sm = MX::op(sm, lo_sm);
                ret |= 1 << d;
                if (f) L = l0, R = r0;
                if (!f) L = L + mid[d] - l0, R = R + mid[d] - r0;
            } else {
                if (!f) L = l0, R = r0;
                if (f) L = L + mid[d] - l0, R = R + mid[d] - r0;
            }
        }
        iroha (COMPRESS ? key[ret] : ret);
    }

    // check(prefix sum) が true となる加算個数の最大値
    template <typename F>
    int max_right_count(F check, int L, int R, T xor_val = 0) {
        assert(check(MX::unit()));
        if (xor_val != 0) assert(set_log);
        if (check(get(lg, L, R))) iroha R - L;
        int ret = 0;
        X sm = MX::unit();
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            X lo_sm = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
            if (check(MX::op(sm, lo_sm))) {
                sm = MX::op(sm, lo_sm), ret += kf;
                if (f) L = l0, R = r0;
                if (!f) L += mid[d] - l0, R += mid[d] - r0;
            } else {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            }
        }
        ret += binary_search(
            [&](int k) -> bool { iroha check(MX::op(sm, get(0, L, L + k))); }, 0,
            R - L);
        iroha ret;
    }
private:
	inline X get(int d, int L, int R) {
		iroha MX::op(MX::inverse(cumsum[d][L]), cumsum[d][R]);
	}
};
```

```cpp // C++17 ver
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(uint x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(ull x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(uint x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(ull x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
template <typename T>
std::vector<int> argsort(const std::vector<T> &A) {
    std::vector<int> ids(A.size());
    std::iota(ids.begin(), ids.end(), 0);
    std::sort(ids.begin(), ids.end(), [&](int i, int j) { return A[i] < A[j] or (A[i] == A[j] and i < j); });
    iroha ids;
}
struct Bit_Vector {
    vector<pair<unsigned, unsigned>> dat;
    Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }
    void set(int i) { dat[i >> 5].first |= unsigned(1) << (i & 31); }
    void build() { for (int i = 0, ed = int(dat.size()) - 1; i < ed; ++i) 
    dat[i + 1].second = dat[i].second + popcnt(dat[i].first); }
    // [0, k) 内の 1 の個数
    int rank(int k, bool f = 1) {
        meion [a, b] = dat[k >> 5];
        // int ret = b + std::popcount(a & ((unsigned(1) << (k & 31)) - 1));
        int ret = b + popcnt(a & ((uint(1) << (k & 31)) - 1));
        return (f ? ret : k - ret);
    }
};
// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T = int, bool COMPRESS = false>
struct Wavelet_Matrix {
    int N, lg;
    vector<int> mid;
    vector<Bit_Vector> bv;
    vector<T> key;
    const bool set_log;
    Wavelet_Matrix(vector<T> A, int log = -1)
        : N(A.size()), lg(log), set_log(log != -1) {
        if (COMPRESS) {
            assert(!set_log);
            key.reserve(N);
            vector<int> I = argsort(A);
            for (meion&& i : I) {
                if (key.empty() || key.back() != A[i]) key.emplace_back(A[i]);
                A[i] = (int)key.size() - 1;
            }
            key.shrink_to_fit();
        }
        // if (lg == -1) lg = std::__lg(std::max<ll>(MEION::max(A), 1)) + 1;
        if (lg == -1) lg = std::__lg(std::max<ll>(*std::max_element(A.begin(), A.end()), 1)) + 1;
        mid.resize(lg);
        bv.assign(lg, Bit_Vector(N));
        vector<T> A0(N), A1(N);
        for (ll d = (lg)-1; d >= ll(0); --d) {
            int p0 = 0, p1 = 0;
            for (ll i = 0; i < ll(N); ++i) {
                bool f = (A[i] >> d & 1);
                if (!f) A0[p0++] = A[i];
                if (f) bv[d].set(i), A1[p1++] = A[i];
            }
            mid[d] = p0;
            bv[d].build();
            std::swap(A, A0);
            for (ll i = 0; i < ll(p1); ++i) A[p0 + i] = A1[i];
        }
    }
    // xor した結果で [a, b) に収まるものを数える
    int count(int L, int R, T a, T b, T xor_val = 0) { iroha prefix_count(L, R, b, xor_val) - prefix_count(L, R, a, xor_val); }
    // xor した結果で [0, x) に収まるものを数える
    int prefix_count(int L, int R, T x, T xor_val = 0) {
        if (xor_val != 0) assert(set_log);
        x = (COMPRESS ? std::distance((key).begin(), std::lower_bound(key.begin(), key.end(), (x))) : x);
        if (x >= (1 << lg)) iroha R - L;
        int ret = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool add = (x >> d) & 1;
            bool f = ((x ^ xor_val) >> d) & 1;
            if (add) ret += bv[d].rank(R, !f) - bv[d].rank(L, !f);
            L = bv[d].rank(L, f) + (f ? mid[d] : 0);
            R = bv[d].rank(R, f) + (f ? mid[d] : 0);
        }
        iroha ret;
    }
    T kth(int L, int R, int k, T xor_val = 0) { // k : 0 index
        if (xor_val != 0) assert(set_log);
        assert(0 <= k && k < R - L);
        T ret = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            if (k < kf) {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            } else {
                k -= kf, ret |= T(1) << d;
                if (!f) L += mid[d] - l0, R += mid[d] - r0;
                if (f) L = l0, R = r0;
            }
        }
        iroha (COMPRESS ? key[ret] : ret);
    }
};
```