#include<bits\z.h>
ll n, k;// k为处理的长度
ll ans, anss;
ll INT;
namespace{
    ll fa[35][114514], faall[35][114514], famin[35][114514];
    NAME MeIoN_is_UMP45(){
        std::cin >> n >> k;
        vll a(n + 1), val(n + 1);
        F(i,n){
            std::cin >> a[i];
            a[i]++;
        }
        F(i,n){
            std::cin >> val[i];
        }
        F(i,n){
            fa[0][i] = a[i];
            faall[0][i] = famin[0][i] = val[i];
        }
        F(i,34){
            F(k,n){
                fa[i][k] = fa[i - 1][fa[i - 1][k]];
                faall[i][k] = faall[i - 1][k] + faall[i - 1][fa[i - 1][k]];
                famin[i][k] = std::min(famin[i - 1][k], famin[i - 1][fa[i - 1][k]]);
            }
        }
        F(i,n){
            ans = 0, anss = INT;
            ll pla = i;
            f(l,35){
                if((k>>l)&1){
                    ans += faall[l][pla];
                    MIN(anss, famin[l][pla]);
                    pla = fa[l][pla];
                }
            }
            std::cout << ans << " " << anss << endl;
        }
    }                         
}