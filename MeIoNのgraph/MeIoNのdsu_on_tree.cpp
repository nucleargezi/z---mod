#include <bits/z.h>
ve<ll> a;
ll ans;
ve<ve<ll>> v;
ve<ll> siz, hpos, res;
// ve<ll> color;
// ll max;
/*获取重儿子*/
inline void work(int n,int fa){
    siz[n] = 1;
    ll max = 0, pos = 0;
    for(meion &i:v[n]){
        if(i==fa) continue;
        work(i, n);
        siz[n] += siz[i];
        if(siz[i]>max){
            max=siz[i];
            pos = i;
        }
    }
    if(max){
        hpos[pos] = 1;
    }
}
/*暴力计算ans*/  /*board*/
inline void DFS(int n,int fa,int p){
    // color[a[n]]++;
    // if(color[a[n]]>max){
    //     max = color[a[n]];
    //     ans = a[n];
    // }elif(color[a[n]]==max) ans+=a[n];
    for(meion &i:v[n]){
        if(i==fa or i==p) continue;
        DFS(i, n, p);
    }
}
/*清除ans*/  /*board*/
inline void init(int n,int fa){
    // color[a[n]]--;
    for(meion &i:v[n]){
        if(i==fa) continue;
        init(i, n);
    }
}
/*启发式合并*/
inline void dfs(int n,int fa){
    ll p=0;
    for(meion &i:v[n]){
        if(i==fa) continue;
        if(not hpos[i]){
            dfs(i, n);
            init(i, n);
            ans = 0;
        }else p=i;
    }
    if(p)
        dfs(p, n);
    DFS(n, fa, p);
    res[n] = ans;
}