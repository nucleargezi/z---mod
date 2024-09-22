#include <bits/z.h> 
ve<ve<P<ll, ll>>> v;
ve<ll> dis;
ve<char> vis;
ll n;
struct takina{
    ll dis,n;
    bool operator>(const takina &a)const{return dis>a.dis;}
};
inline void dijkstra(ll LF){
    dis.assign(n+1,INT);
    vis.assign(n+1,false);
    dis[LF]=0;
    std::priority_queue<takina,std::vector<takina>,std::greater<takina>>q;
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

struct takina{
    ll dis, n;
    bool operator>(const takina& a) const { return dis > a.dis; }
};
    meion dij = [&] (int n) {
        dis.assign(::n + 1, INT);
        vis.assign(::n + 1, 0);
        dis[n] = 0;
        std::priority_queue<takina, std::vector<takina>, std::greater<takina>> q;
        q.push({ 0, n });
        while (q.size()) {
            int n = q.top().n;
            q.pop();
            if (vis[n]) continue;
            vis[n] = true;
            for (meion & [ i, val ] : v[n]) {
                if (dis[i] > dis[n] + val) {
                    dis[i] = dis[n] + val;
                    q.push({ dis[i], i });
                }
            }
        }
    };