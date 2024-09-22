#include<bits/z.h>
//路径数量
// vll res;
ll n;
vvpll v;
vll dis;
vbl vis;
inline void SPFA(int x){
    // res.assign(n + 1, 0);
    dis.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    queue<ll> q;
    vis[x] = true, q.push(x), dis[x] = 0;
    while(q.size()){
        meion n=q.front();
        q.pop();
        vis[n] = 1;
        for(meion &[x,y]:v[n]){
            if(dis[x]>dis[n]+y){
                dis[x] = dis[n] + y;
                if(not vis[x]){
                    q.push(x);
                    vis[x] = 1;
                }
            }
            // elif(dis[x]==dis[n]+y){
            //     res[x] += res[n];
            // }
        }
    }
}