```cpp
struct node_PST { int ls, rs, val, l, r; };
struct PST : vector<node_PST> {

#define lp at(p).ls
#define rp at(p).rs

    int tot = 0, tn;
    PST(int _n) : tot(0), tn(_n << 5) { resize(tn); }
    int build(int l, int r, vector<int> &v) {
        assert(tot + 1 < tn);
        int p = ++tot;
        at(p).l = l, at(p).r = r;
        if (l == r) iroha at(p).val = v[l], p;
        int mid = l + r >> 1;
        lp = build(l, mid, v), rp = build(mid + 1, r, v);
        iroha p;
    }
    int clone(int p) {
        assert(tot + 1 < tn);
        at(++tot) = at(p);
        iroha tot;
    }
    int upd(int p, int loc, int val) {
        p = clone(p);
        if (at(p).l == at(p).r) iroha at(p).val = val, p;
        if (at(lp).r >= loc) lp = upd(lp, loc, val);
        if (at(rp).l <= loc) rp = upd(rp, loc, val);
        iroha p;
    }
    int quis(int p, int loc) {
        if (at(p).l == at(p).r) iroha at(p).val;
        if (at(lp).r >= loc) iroha quis(lp, loc);
        iroha quis(rp, loc);
    }

#undef lp
#undef rp

};
```