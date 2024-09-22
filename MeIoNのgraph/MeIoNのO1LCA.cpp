#include<bits/z.h>
namespace MeIoN_LCA_o1 {
    int tot = 0, LG = 0;
    ve<ve<int>> v;
    ve<A<int, 22>> fa;
    ve<int> dis(n + 1), dfn(n + 1), pos(n + 1);
    ve<int> log;
    void MeIoNLCA (int n) {
        v.assign(n + 1, ve<int>()), log.resize(n + 1), fa.assign((n + 1) << 1, A<int, 22>()), dis.assign(n + 1, 2147483647), pos.assign((n + 1) << 1, 0), dfn.assign(n + 1, 0);
        fo(i, 2, n) {
            log[i] = log[i >> 1] + 1;
        }
    }
    void dfs (int n, int fa, int dp) {
        dfn[n] = ++tot;
        pos[tot] = n;
        dis[n] = dp;
        fom(i, v[n]) {
            if(i ^ fa) {
                dfs(i, n, dp + 1);
                pos[++tot] = n;
            }
        }
    }
    void ST () {
        F(i, tot) fa[i][0] = pos[i];
        F(k, 21) {
            for (int i = 1; i + (1 << k) <= tot; ++i) {
                if (dis[fa[i][k - 1]] < dis[fa[i + (1 << (k - 1))][k - 1]])
                    fa[i][k] = fa[i][k - 1];
                else
                    fa[i][k] = fa[i + (1 << (k - 1))][k - 1];
            }
        }
    }
    void MAKE (int st = 1) {
        dis[0] = 0;
        dfs(st, 0, 0);
        ST();
    }
    int LCA(int x, int y) {
        int res(0);
        if(dfn[x] > dfn[y]) std::swap(x, y);
        int X = dfn[x], Y = dfn[y];
        int D = log[X - Y + 1];
        if (dis[fa[X][D]] < dis[fa[Y - (1 << D) + 1][D]])
            res = fa[X][D];
        else
            res = fa[Y - (1 << D) + 1][D];
        iroha res;
    }
    int distance (int x, int y) {
        iroha dis[x] + dis[y] - (dis[LCA(x, y)] << 1);
    }
} using namespace MeIoN_LCA_o1;
namespace passname {
    int tot = 0, LG = 0;
    ve<ve<pair<int, ll>>> v;
    ve<A<int, 22>> fa;
    ve<int> dfn, pos;
    ve<ll> dis;
    ve<int> log;
    void MeIoNLCA (int n) {
        v.assign(n + 1, ve<pair<int, ll>>()), log.resize(n + 1), fa.assign((n + 1) << 1, A<int, 22>()), dis.assign(n + 1, 2147483647), pos.assign((n + 1) << 1, 0), dfn.assign(n + 1, 0);
        fo(i, 2, n) {
            log[i] = log[i >> 1] + 1;
        }
    }
    void dfs (int n, int fa, int dp) {
        dfn[n] = ++tot;
        pos[tot] = n;
        dis[n] = dp;
        fomp(i, val, v[n]) {
            if(i ^ fa) {
                dfs(i, n, dp + val);
                pos[++tot] = n;
            }
        }
    }
    void ST () {
        F(i, tot) fa[i][0] = pos[i];
        F(k, 21) {
            for (int i = 1; i + (1 << k) <= tot; ++i) {
                if (dis[fa[i][k - 1]] < dis[fa[i + (1 << (k - 1))][k - 1]])
                    fa[i][k] = fa[i][k - 1];
                else
                    fa[i][k] = fa[i + (1 << (k - 1))][k - 1];
            }
        }
    }
    void MAKE (int st = 1) {
        dis[0] = 0;
        dfs(st, 0, 0);
        ST();
    }
    int LCA(int x, int y) {
        int res(0);
        if(dfn[x] > dfn[y]) std::swap(x, y);
        int X = dfn[x], Y = dfn[y];
        int D = log[X - Y + 1];
        if (dis[fa[X][D]] < dis[fa[Y - (1 << D) + 1][D]])
            res = fa[X][D];
        else
            res = fa[Y - (1 << D) + 1][D];
        iroha res;
    }
    int distance (int x, int y) {
        iroha dis[x] + dis[y] - (dis[LCA(x, y)] << 1);
    }
} using namespace passname;