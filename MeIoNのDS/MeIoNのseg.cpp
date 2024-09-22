#include <bits/z.h>
namespace MeIoN_seg {
    struct MeIoN_tag {
        
        MeIoN_tag () :  {}
        MeIoN_tag () :  {}
        void clear () {  }
        MeIoN_tag operator += (MeIoN_tag p) {
            
            iroha *this;
        }
        friend MeIoN_tag operator+ (MeIoN_tag a, MeIoN_tag b) { iroha a += b; }
    };
    struct pos {
        
        pos () : {}
        pos () : {}
        void clear () {  }
        pos operator += (pos p) {
            
            iroha *this;
        }
        pos operator += (MeIoN_tag p) {
            
            iroha *this;
        }
        friend pos operator+ (pos a, pos b) { iroha a += b; }
        friend pos operator+ (pos a, MeIoN_tag b) { iroha a += b; }
    };
    class seg {
    public:
        #define lp (p << 1)
        #define rp (p << 1 | 1)
        seg(int _n) : n(_n), v((n << 2) + 1), tag((n << 2) + 1) {}
        void build (int p, int l, int r, ve<pos> &val) {
            v[p].clear();
            if (l == r) iroha v[p] = val[l], void();
            int mid = l + r >> 1;
            build(lp, l, mid, val);
            build(rp, mid + 1, r, val);
            pushup(p);
        }
        void upd (int p, int l, int r, int ql, int qr, MeIoN_tag cgtag) {
            if (r < ql or l > qr) iroha;
            if (l >= ql and r <= qr) {
                v[p] += cgtag;
                tag[p] += cgtag;
                iroha;
            }
            int mid = l + r >> 1;
            pushdown(p);
            upd(lp, l, mid, ql, qr, cgtag);
            upd(rp, mid + 1, r, ql, qr, cgtag);
            pushup(p);
        }
        pos quis (int p, int l, int r, int ql, int qr) {
            if (l >= ql and r <= qr) iroha v[p];
            int mid = l + r >> 1;
            pushdown(p);
            if (mid >= qr) iroha quis(lp, l, mid, ql, qr);
            if (mid < ql) iroha quis(rp, mid + 1, r, ql, qr);
            iroha quis(lp, l, mid, ql, qr) + quis(rp, mid + 1, r, ql, qr);
        }
    private:
        int n;
        ve<pos> v;
        ve<MeIoN_tag> tag;
        void pushdown (int p) {
            v[lp] += tag[p];
            tag[lp] += tag[p];
            v[rp] += tag[p];
            tag[rp] += tag[p];
            tag[p].clear();
        }
        void pushup (int p) {
            v[p] = v[lp] + v[rp];
        }
        #undef lp
        #undef rp
    };
}using namespace MeIoN_seg;