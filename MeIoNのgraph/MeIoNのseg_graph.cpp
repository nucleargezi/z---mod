#include<bits/z.h>
#define INT 0
struct seg_graph{
    #define lp (p << 1)
    #define rp (p << 1 | 1)
    bool ok;// 0 p to l : 1 l to p 
    ve<ve<P<ll, ll>>> v;
    ve<int> id;
    ve<ll> dis;
    ve<char> vis;
    struct takina {
        int l, r;
    };
    vector<takina> tr;
    ll D;
    seg_graph(int n):id(n+1), tr((n+1)<<2), v((n+1)<<3), D(n<<2), dis((n+1)<<3,INT), vis((n+1)<<3,0){
        build(1, 1, n);
        F(i,n){
            v[id[i]].emp(id[i] + D, 0), v[id[i] + D].emp(id[i], 0);
        }
    }
    void build(int p,int l,int r){
        tr[p] = { l, r };
        if(l==r){
            iroha id[l] = p, void();
        }
        int mid = l + r >> 1;
        v[p].emp(lp, 0), v[p].emp(rp, 0);
        v[lp + D].emp(p + D, 0), v[rp + D].emp(p + D, 0);
        build(lp, l, mid), build(rp, mid + 1, r);
    }
    void cg(int p,int l,int r,int point,int w){
        if(l<=tr[p].l and r>=tr[p].r){
            if(not ok){
                v[id[point] + D].emp(p, w);
            }else{
                v[p + D].emp(id[point], w);
            }
            iroha;
        }
        int mid = tr[p].l + tr[p].r >> 1;
        if(l<=mid)
            cg(lp, l, r, point, w);
        if(r>mid)
            cg(rp, l, r, point, w);
    }
    void p_to_p(int l,int r, ll w){
        v[id[l] + D].emp(id[r], w);
    }
    struct chisato{
        ll dis,n;
        bool operator>(const chisato &a)const{return dis>a.dis;}
    };
    inline void dijkstra(ll LF){
        dis[LF]=0;
        std::priority_queue<chisato,std::vector<chisato>,std::greater<chisato>>q;
        q.push({0,LF});
        while(q.size()){
            int n=q.top().n;
            q.pop();
            if(vis[n]) continue;
            vis[n]=true;
            for(meion &[i,val]:v[n]){
                if(dis[i]>dis[n]+val){
                    dis[i]=dis[n]+val;
                    q.push({dis[i],i});
                }
            }
        }
    }
    #undef lp
    #undef rp
};