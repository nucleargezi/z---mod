#include<bits/z.h>

const int N = 4e6 + 5, M = 1e5 + 5;

//seg是树的值 ls是左儿子 rs是右儿子 lazy是懒标记
//lson rson 用来优化代码量

int ver[M], idx, n, m;
//ver代表着每一次修改的根节点下标 idx辅助开点
namespace segtree{
    #define seg(x) tree[x].val
    #define ls(x) tree[x].l
    #define rs(x) tree[x].r
    #define lson(x) tree[x].l, l, mid
    #define rson(x) tree[x].r, mid + 1, r
    #define lazy(x) tree[x].lazy

    struct Segtree {
        ll val;
        int l, r, lazy;
    }tree[4145141];

    void build(int k, int l, int r) {
        seg(k) = lazy(k) = 0;//多测清空
        if (l == r) return void(std::cin >> seg(k));//构建方式可参考线段树
        int mid = l + r >> 1;
        //动态开点确保空间复杂度
        ls(k) = ++idx, rs(k) = ++idx;
        build(lson(k)), build(rson(k));
        seg(k) = seg(ls(k)) + seg(rs(k));
    }

    //pre代表着历史版本
    void upd(int pre, int k, int l, int r, int x, int y, int z) {
        tree[k] = tree[pre];//先让其等于历史值
        if (l >= x && r <= y) {
            lazy(k) += z;
            seg(k) += z * (r - l + 1);
            return;
        }
        int mid = l + r >> 1;
        //在修改的同时动态开点
        if (x <= mid) ls(k) = ++idx, upd(ls(pre), lson(k), x, y, z);
        if (y > mid) rs(k) = ++idx, upd(rs(pre), rson(k), x, y, z);
        seg(k) = seg(ls(k)) + seg(rs(k)) + lazy(k) * (r - l + 1);//注意同时加上懒标记
    }

    //因为空间大小原因不可下放标记 利用永久化标记 mark 辅助查询
    ll qry(int k, int l, int r, int x, int y, ll mark) {
        if (l >= x && r <= y) return seg(k) + (r - l + 1) * mark;
        int mid = l + r >> 1;
        ll res = 0;
        if (x <= mid) res += qry(lson(k), x, y, mark + lazy(k));
        if (y > mid) res += qry(rson(k), x, y, mark + lazy(k));
        return res;
    }
} using namespace segtree;

void solve() {

    std::cin >> n >> m;

    idx = 0;
    ver[0] = ++idx;
    build(ver[0], 1, n);

    char op; int x, y, z, now = 0;
    for (int i = 1; i <= m; ++i) {
        std::cin >> op;
        if (op == 'C') {
            std::cin >> x >> y >> z;
            ver[++now] = ++idx;
            upd(ver[now - 1], ver[now], 1, n, x, y, z);
        }
        else if (op == 'Q') {
            std::cin >> x >> y;
            std::cout << qry(ver[now], 1, n, x, y, 0) << '\n';
        }
        else if (op == 'H') {
            std::cin >> x >> y >> z;
            std::cout << qry(ver[z], 1, n, x, y, 0) << '\n';
        }
        else if (op == 'B'){
            std::cin >> now;
        }
    }
}

/*
使用：给出一个区间 <[x, y]> 和 <历史版本z> 或 <修改值z>

<预处理线段树，版本从 0 开始>
*idx = 0, ver[0] = ++idx，build(ver[now], 1, n) 

<使当前版本的区间 [x, y] 同时加上一个值 z ，并更新当前版本> (Change)
-ver[++now] = ++idx <更新版本>
-upd(ver[now - 1], ver[now], 1, n, x, y, z); 

<查询当前版本区间 [x, y] 的数字的和> (Query)
-qry(ver[now], 1, n, x, y, 0)

<查询第 z 次修改的版本区间 [x, y] 的数字的和> (History)
-qry(ver[z], 1, n, x, y, 0)

<将当前版本回溯至第 z 次修改的版本> (Back)
-now = z

以上四种操作分别对应 solve() 中: op = C, Q, H, B。
单次修改需要的空间开销很大，请不要吝啬空间，能开多大则开多大。
<除动态开点及宏定义外，其他内容与线段树结构相似>
*/