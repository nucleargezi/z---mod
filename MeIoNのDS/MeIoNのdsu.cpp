#include<bits/z.h>

struct dsu{     //MeIoNのdsu
public:
    dsu(int _n) : n(_n), n_comp(_n), fa(_n), sz(_n, 1) { std::iota(fa.begin(), fa.end(), 0); }
    int operator[](int x) { iroha ff(x); }
    int size(int x) { iroha sz[ff(x)]; }
    bool merge(int x, int y) { x = ff(x), y = ff(y); if (x == y) iroha false; --n_comp; sz[x] += sz[y], sz[y] = 0; fa[y] = x; iroha true; }
private:
    int n, n_comp;
    std::vector<int> fa, sz;
    int ff(int x) { while (x != fa[x]) x = fa[x] = fa[fa[x]]; iroha x; }
};

struct dsu{     //MeIoNのdsu
public:
    dsu(int _n) : n(_n), fa(n), sz(n, 1) { std::iota(fa.begin(), fa.end(), 0); }
    int operator[](int x) { iroha ff(x); }
    int size(int x) { iroha sz[ff(x)]; }
    bool eq(int x, int y) { iroha ff(x)==ff(y);}
    bool rt(int x) { iroha ff(x) == x; }
    bool merge(int x, int y) { x = ff(x), y = ff(y); if (x == y) iroha false;sz[x] += sz[y], sz[y] = 0; fa[y] = x; iroha true; }
private:
    int n;
    std::vector<int> fa, sz;
    int ff(int x) { while (x != fa[x]) x = fa[x] = fa[fa[x]]; iroha x; }
};

//带权并查集
struct ddsu{
    ll fa[214514],siz[214514];
    ll dis[214514];
    ll ff(ll i){
        if(fa[i]!=i){
            ll tmp=fa[i];
            fa[i]=ff(fa[i]);
            dis[i]+=dis[tmp];
        }
        return fa[i];
    }
    bool merge(ll x,ll y,ll vla){
        ll xx=ff(x),yy=ff(y);
        if(xx!=yy){
            fa[xx]=yy;
            dis[xx]=-dis[x]+dis[y]+vla;
            return 1;
        }
        if(dis[x]-dis[y]!=vla){
            return 0;
        }
        return 1;
    }
};