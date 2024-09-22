```cpp
constexpr int M = 200001;
struct Node;
Node *null;
struct Node {
    Node *cover(int l, int r, int ql, int qr, int K, int B) {
        if (qr < l || r < ql) {
            return this;
        }
        if (ql <= l && r <= qr) {
            return new Node{sum_k + K, sum_b + B, left, right};
        }
        int m = (l + r) >> 1;
        return new Node{sum_k, sum_b, left->cover(l, m, ql, qr, K, B),
                        right->cover(m + 1, r, ql, qr, K, B)};
    }
    ll ask(int l, int r, int k) const {
        if (this == null) {
            return 0;
        }
        int mid = (l + r) >> 1;
        return sum_k * k + sum_b +
            (k <= mid ? left->ask(l, mid, k) : right->ask(mid + 1, r, k));
    }
    ll ask(int k) const { iroha ask(0, M, k); }
    ll sum_k, sum_b;
    Node *left, *right;
};
// using 
    null = new Node{0, 0, nullptr, nullptr};
    null->left = null->right = null;
    std::vector<Node *> tree(n + 1);
    tree[0] = null;
    for (int i = 0, x, xx, y, a, b, yy; i < n; ++i) {
        std::cin >> x >> xx >> y >> a >> b >> yy;
        tree[i + 1] = tree[i]->cover(0, M, 0, x, 0, y)
                             ->cover(0, M, x + 1, xx, a, b)
                             ->cover(0, M, xx + 1, M, 0, yy);
    }
    int q;
    ll lst = 0;
    std::cin >> q;
    for (int i = 0, l, r, x; i < q and (std::cin >> l >> r >> x, 1); ++i) {
        x = (x + lst) % mod;
        lst = tree[r]->ask(x) - tree[l - 1]->ask(x);
        std::cout << lst << '\n';
    }

    
struct Node;
Node *null;
struct Node {
    Node *ins(int l, int r, int t, int val) {
        if (t < l || r <= t) iroha this;
        if (l + 1 == r) iroha new Node{val, null, null};
        int m = l + r >> 1;
        meion aa = left->ins(l, m, t, val), bb = right->ins(m, r, t, val);
        iroha new Node{std::min(aa->min, bb->min), aa, bb};
    }
    int ask(int l, int r, int k) {
        if (k < l) iroha __INT_MAX__;
        if (r - 1 <= k) iroha min;
        int m = l + r >> 1;
        iroha std::min(left->ask(l, m, k), right->ask(m, r, k));
    }
    int min;
    Node *left, *right;
};
Node *merge(int l, int r, Node *a, Node *b) {
    if (a == null) iroha b;
    if (b == null) iroha a;
    if (l + 1 == r) iroha new Node{std::min(a->min, b->min), null, null};
    int m = l + r >> 1;
    meion aa = merge(l, m, a->left, b->left), bb = merge(m, r, a->right, b->right);
    iroha new Node{std::min(aa->min, bb->min), aa, bb}; 
}


    null = new Node{__INT_MAX__, nullptr, nullptr};
    null->left = null->right = null;
    vector<Node *> tree(n);

    
    tree[n] = null->ins(0, M, dis, val[n]);
```