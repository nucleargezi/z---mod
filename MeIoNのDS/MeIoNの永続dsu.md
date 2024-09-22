```cpp
struct everlasting_dsu {
    static const int N = 214514;
    int fa[35 * N], dep[35 * N];
    int ls[35 * N], rs[35 * N];
    int rt[N], tot;
    int n, m;

    void build(int &u, int l, int r) {
        u = ++tot;
        if (l == r) { fa[u] = l; return ; }
        int mid = l + r >> 1;
        build(ls[u], l, mid), build(rs[u], mid + 1, r);
    }
    void build(int _n) { n = _n; build(rt[0], 1, n); }
    void update(int &u, int v, int l, int r, int pos, int Fa) {
        u = ++tot, ls[u] = ls[v], rs[u] = rs[v], fa[u] = fa[v], dep[u] = dep[v];
        if (l == r) { fa[u] = Fa; return ; }
        int mid = l + r >> 1;
        if (pos <= mid) update(ls[u], ls[v], l, mid, pos, Fa);
        else update(rs[u], rs[v], mid + 1, r, pos, Fa);
    }
    void add(int u, int l, int r, int pos) {
        if (l == r) { dep[u]++; return ; }
        int mid = l + r >> 1;
        if (pos <= mid) add(ls[u], l, mid, pos);
        else add(rs[u], mid + 1, r, pos);
    }
    int query(int u, int l, int r, int pos) {
        if (l == r) return u;
        int mid = l + r >> 1;
        if (pos <= mid) return query(ls[u], l, mid, pos);
        else return query(rs[u], mid + 1, r, pos);
    }
    int find(int opt, int x) {
        int Fa = query(opt, 1, n, x);
        if (x == fa[Fa]) return Fa;
        else return find(opt, fa[Fa]); 
    }
} g;
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    g.build(n);
    for (int i = 1, op, x, y, k; i < m + 1 and (std::cin >> op, 1); ++i) {
        if (op == 1) {
            g.rt[i] = g.rt[i - 1];
            std::cin >> x >> y;
            x = g.find(g.rt[i], x), y = g.find(g.rt[i], y);
            if (g.fa[x] == g.fa[y]) continue;
            if (g.dep[x] > g.dep[y]) std::swap(x, y);
            g.update(g.rt[i], g.rt[i - 1], 1, n, g.fa[x], g.fa[y]);
            if (g.dep[x] == g.dep[y]) g.add(g.rt[i], 1, n, g.fa[y]);
        } else if (op == 2) {
            std::cin >> k;
            g.rt[i] = g.rt[k];
        } else {
            g.rt[i] = g.rt[i - 1];
            std::cin >> x >> y;
            x = g.find(g.rt[i], x), y = g.find(g.rt[i], y);
            std::cout << (g.fa[x] == g.fa[y]) << '\n';
        }
    }
}
```