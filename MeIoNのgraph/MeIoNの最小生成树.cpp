#include<bits\z.h>
using namespace std;
using ll=long long;ll ans,anss;
#define INT 1

ve<ve<P<int, int>>> v;
ll ans,anss,n,m;
void SCC(){
    rpq<P<int, int>> q;
    ve<ll> dis(n + 1, INT);
    ve<char> vis(n + 1, false);
    dis[0] = 0;
    ans = anss = 0;
    q.push({0, 0});  
    while (q.size()) {
        if (ans > n) break;
        auto [val, n] = q.top();
        q.pop();
        if (vis[n]) continue;
        vis[n] = true;
        ans++;
        anss += val;
        for(meion &[i, w] : v[n]){
            if(w < dis[i]){
                dis[i] = w;
                q.push({w, i});
            }
        }
    }
};


    meion scc = [&] () {
        rpq<P<int, int>> q;
        ve<ll> dis(n + 1, INT);
        ve<char> vis(n + 1);
        dis[0] = 0;
        ll res = 0;
        q.push({0, 0});
        while (q.size()) {
            meion [val, n] = q.top();
            q.pop();
            if (vis[n]) continue;
            vis[n] = 1;
            res += val;
            for (meion & [i, w] : v[n]) {
                if (w < dis[i]) {
                    dis[i] = w;
                    q.push({w, i});
                }
            }
        }
        iroha res;
    };


int main(){
    ans=anss=0;
    if(ans==n)
        std::cout<<anss<<endl;
    else
        std::cout<<"NO\n";
    return 'A';
}