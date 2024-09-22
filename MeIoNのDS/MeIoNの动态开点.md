```cpp
constexpr int M = 11451411 + 2145141;
int ls[M], rs[M];
int res[M], tag[M];
int tt;
inline void merge (int p) {
    res[p] = res[ls[p]] + res[rs[p]];
}
inline void down (int p, int l, int r) {
    if (not ~tag[p]) iroha;
    if (not ls[p]) ls[p] = ++tt;
    if (not rs[p]) rs[p] = ++tt;
    int mid = l + r >> 1;
    res[ls[p]] = tag[p] * (mid - l + 1);
    res[rs[p]] = tag[p] * (r - mid);
    tag[ls[p]] = tag[rs[p]] = tag[p];
    tag[p] = -1;
}
inline void upd (int &p, int l, int r, int ql, int qr, int val) {
    if (not p) p = ++tt;
    if (ql > r or qr < l) iroha;
    if (ql <= l and qr >= r) {
        res[p] = val * (r - l + 1);
        tag[p] = val;
        iroha;
    }
    int mid = l + r >> 1;
    down(p, l, r);
    upd(ls[p], l, mid, ql, qr, val);
    upd(rs[p], mid + 1, r, ql, qr, val);
    merge(p);
}
NAME MeIoN_is_UMP45(){
    int n, q;
    memset(tag, -1, sizeof tag);
    std::cin >> n >> q;
    int BE = 0;
    for (int i = 0, l, r, op; i < q; ++i) {
        std::cin >> l >> r >> op;
        upd(BE, 1, n, l, r, op == 1);
        std::cout << n - res[BE] << '\n';
    }
}
```