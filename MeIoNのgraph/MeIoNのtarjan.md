```cpp
namespace MeIoN_tarjan{
    // ve<ve<P<ll, ll>>> v,g;
    ve<ve<int>> v, g;
    ve<ll> dfn, low, tarjan_stk, id, sz, val;
    ve<char> vis;
    ll cnt, tot;
    void MeIoN_tarjan(ll n,ll fa){
        dfn[n] = low[n] = ++tot;
        vis[n] = true;
        tarjan_stk.emp(n);
        // for (meion &[i,val]:v[n]){
        for (meion &i : v[n]) {
            // if(i==fa) continue;
            if (!dfn[i]){
                MeIoN_tarjan(i, n);
                low[n] = std::min(low[n], low[i]);
            } else if (vis[i]){
                low[n] = std::min(low[n], dfn[i]);
            }
        }
        if(dfn[n]==low[n]){
            ++cnt;
            while (tarjan_stk.size()){
                ll v=tarjan_stk.back();
                tarjan_stk.pop_back();
                id[v] = cnt, sz[cnt]++, vis[v] = 0;
                if (v==n)
                    break;
            }
        }
    }
    void build(ll n){
        tarjan_stk.clear();
        dfn.assign(n + 1, 0), low.assign(n + 1, 0), id.assign(n + 1, 0), sz.assign(n + 1, 0), val.assign(n + 1, 0);
        cnt = tot = 0;
        vis.assign(n + 1, 0);
        f(i, n) if (!dfn[i]) MeIoN_tarjan(i, -1), tarjan_stk.clear();
    }
}using namespace MeIoN_tarjan;
// open and ...    all 0 index
    ve<int> dfn(n), low(n), id(n), sz(n), stk;
    ve<char> vis(n);
    int cnt = 0, tot = 0;
    meion tj = [&] (meion &&se, int n, int fa)->void {
        dfn[n] = low[n] = ++tot;
        vis[n] = 1;
        stk.emp(n);
        fom (i, v[n]) {
            if (not dfn[i]) {
                se(se, i, n);
                low[n] = std::min(low[n], low[i]);
            } else if (vis[i]) {
                low[n] = std::min(low[n], dfn[i]);
            }
        }
        if (dfn[n] == low[n]) {
            while (1) {
                int v = stk.back();
                stk.pop_back();
                id[v] = cnt, sz[cnt]++, vis[v] = 0;
                if (v == n) break;
            } ++cnt;
        }
    };
    f(i, n) if (not dfn[i]) tj(tj, i, i), stk.clear();
    // new graph
    ve<ve<int>> g(cnt);
    // ve<ve<int>> scc(cnt);
    ve<int> in(cnt);
    f(i, n) {
        // scc[id[i]].emp(i);
        for (meion &x : v[i]) {
            if (id[i] != id[x]) {
                g[id[i]].emp(id[x]);
            }
        }
    }
    for (meion &v : g) {
        unique(v);
        for (meion &i : v) {
            ++in[i];
        }
    }

// 割点
    ve<int> dfn(n), low(n), id(n), sz(n), stk;
    ve<char> vis(n);
    ve<int> point;
    int cnt = 0, tot = 0;
    int root;
    meion tj = [&] (meion &&se, int n, int fa)->void {
        dfn[n] = low[n] = ++tot;
        vis[n] = 1;
        stk.emp(n);
        int son = 0;
        fom (i, v[n]) {
            if (not dfn[i]) {
                se(se, i, n);
                low[n] = std::min(low[n], low[i]);
                son += n == root;
                if (n != root and dfn[n] <= low[i]) {
                    point.emp(n);
                }
            } else if (vis[i]) {
                low[n] = std::min(low[n], dfn[i]);
            }
        }
        if (n == root and son > 1) {
            point.emp(n);
        }
        if (dfn[n] == low[n]) {
            while (stk.size()) {
                int x = stk.back();
                stk.pop_back();
                id[x] = cnt, sz[cnt]++, vis[x] = 0;
                if (x == n) break;
            } ++cnt;
        }
    };
    f(i, n) if (not dfn[i]) root = i, tj(tj, i, i), stk.clear();
    unique(point);
    UL(point.size());
    fom (i, point) UU(i + 1); UL();