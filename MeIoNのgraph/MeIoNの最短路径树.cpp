#include<bits\z.h>
#define INT 0
ll n, m, k, ans, anss;
ve<ve<P<ll, ll>>> v;
ve<ll> dis;
ve<char> vis;
ve<ve<ll>> out;
ve<ve<ll>> res;
ve<ll> an;
ve<ll> stk;
ve<ll> w;
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
        fomp(i,val,v[n]){
            if(dis[i]==dis[n]+w[val]){
                out[i].clear();
                out[i].emp(val);
            }
            if(dis[i]>dis[n]+w[val]){
                out[i].clear();
                dis[i] = dis[n] + w[val];
                out[i].emp(val);
                q.push({dis[i],i});
            }
        }
    }
}
void dfs(int x){
    if(not k){     //times;
        iroha;
    }
    if(x==stk.size()){
        res.pb(an);
        k--;
        iroha;
    }
    int n = stk[x];
    fom(i,out[n]){
        an[i] = 1;
        dfs(x + 1);
        an[i] = 0;
    }
}
NAME MeIoN_is_UMP45(){
    std::cin >> n >> m;
    w.assign(m, 0);
    out = ve<ve<ll>>(n + 1, ve<ll>(0));
    v.assign(n + 1, ve<P<ll, ll>>(0));
    ve<P<ll, ll>> e(m);
    fomp(l,r,e){
        std::cin >> l >> r >> w[ans];
        v[l].emp(r, ans);
        v[r].emp(l, ans);
        ans++;
    }
    ll be;
    std::cin >> be;
    dijkstra(be);
    an.assign(m, 0);
    k = 1;
    fo(i,1,n){
        if (i==be) continue;
        if (out[i].size()==1){
            an[out[i].back()] = 1;
        } else {
            stk.emp(i);
        }
    }
    dfs(0);
    ans = anss = 0;
    ve<ll> ansss;
    fom(i,res[0]){
        if(i)
            ans += w[anss], ansss.emp(anss + 1);
        anss++;
    }
    std::cout << ans << endl;
    fom(i, ansss) std::cout << i << " ";
}