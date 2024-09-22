// 雪と風 星の飛ぶ夜も 心いつも 彼方を目指す
#include <iostream>
#include <bitset>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <functional>
#include <fstream>
#include <limits>
#include <cassert>

using ll     =   long long;
using ull    =   unsigned long long;
using ld     =   long double;
using int128 =   __int128;
using ar     =   std::array<ll,2>;
using arr    =   std::array<ll,3>;
using pii    =   std::pair<int,int>;
using pll    =   std::pair<ll,ll>;
using pld    =   std::pair<ld,ld>;
using vint   =   std::vector<int>;
using vll    =   std::vector<ll>;
using vld    =   std::vector<ld>;
using vpll   =   std::vector<pll>;
using var    =   std::vector<ar>;
using varr   =   std::vector<arr>;
using vbl    =   std::vector<bool>;
using vvl    =   std::vector<vll>;
using vvpll  =   std::vector<vpll>;
using vvarr  =   std::vector<varr>;
using sei    =   std::set<int>;
using sel    =   std::set<ll>;
using mii    =   std::map<int,int>;
using mil    =   std::map<int,ll>;
using mll    =   std::map<ll,ll>;
using mlv    =   std::map<ll,vll>;
using pql    =   std::priority_queue<ll>;
using rpql   =   std::priority_queue<ll,vll,std::greater<ll>>;
using pqpll  =   std::priority_queue<pll>;
using rpqpll =   std::priority_queue<pll,vpll,std::greater<pll>>;

#define hello_world()   std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0)
#define f(i,n)          for(ll i=0;i<(n);i++) 
#define F(i,n)          for(ll i=1;i<=(n);i++) 
#define fo(i,a,b)       for(ll i=(a);i<=(b);i++) 
#define innt(a)         for(auto &i:a) std::cin>>i;
#define If()            if()
#define el              else
#define elif            else if
#define endl            "\n"
#define Endl            "\n"
#define Tsuchinaga      k
#define Mimori          p
#define emp             emplace_back
#define pb              push_back
#define lp              (p<<1)
#define Yutori          c
#define rp              (p<<1|1)
#define Sort(v)         std::sort(v.begin(),v.end())
#define Sakurako        j
#define makestr(a)      #a
#define re(s)           std::reverse(s.begin(),s.end())
#define enter           std::cout<<"\n"
#define Natsu           d
#define Seia            h
#define nop             std::string::npos
#define catstr(a,b)     a##b
#define hina            ai
#define Murakasa        e
#define iori            F
#define Yurizono        g
#define ca(a,b)         catstr(a,b)
#define lf(sth)         el
#define Utazumi         i
#define pi              3.1415926535897932384626433832795
#define Hiyori          l
#define Mizuha          o
#define ms(a)           makestr(a)
#define Kayoko          r
#define Hatsune         s
#define cas(a,b,c)      ca(a,ca(b,c))
#define pt(str)         std::cout<<ms(str)
#define Onikata         q
#define plana           m
#define alona           n
#define miku            t
#define wall            std::cout<<"________________________________________________________________"<<endl
#define preans()        std::vector<ll>anss
#define cion            cin
#define ciN             cin
#define whiel           while
#define Hakari          a
#define Atsuko          b
#define whlie           while
#define vla             val
#define asn             ans
#define AC(a,b)         ca(b,a)
#define MeIoN()         0
#define NAME            inline void
#define meion           auto
#define iroha           return
#define schale(a)       ca(plana,a)

/*
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠤⡛⠄⠄⠄⠄⠄⠛⣾⣾⡾⣮⣭⣭⣭⣮⡾⢿⣾⣝⠛⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠛⡾⡏⣮⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⢿⡾⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡛⣮⢸⡛⣏⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣾⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡛⣭⣮⢸⣏⣭⣫⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣾⣾⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣾⣭⣭⢸⢸⣭⢸⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⡾⣾⢿⢿⢿⢿⢿⣾⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣏⣭⣭⣮⡏⣭⣫⣮⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⢿⢿⢿⢿⢿⢿⢿⢿⢿⢿⢿⠒⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣭⣭⣭⢸⡏⣭⡏⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⡾⢿⢿⢿⢿⢿⢿⢿⢿⣾⢿⢿⢿⢿⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣮⣭⣭⢸⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⢿⢿⢿⢿⢿⢿⢿⢿⢿⣷⣾⢿⢿⢿⣷⢿⢿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⢃⢃⡏⢘⠄⠄⠄⠄⠄⠄⣭⣭⣏⢸⣭⢸⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣾⣾⢿⢿⢿⣾⣷⢿⢿⢿⢿⢿⢿⣷⡛⡛⢃⣀⠤⡛⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⠒⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⢃⢸⡲⢸⢸⣫⣝⠤⣀⣭⣭⡏⡛⣭⣭⣭⣭⡏⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣮⣮⣮⢿⢿⣾⣷⣾⢿⢿⢿⢿⣷⣭⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠲⣀⣀⡾⠄⠄⠄⠄⠄⠄⣀⢸⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⡾⡏⢸⣏⣫⣫⣫⣫⣭⣭⣝⡏⣭⣝⣝⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣝⡾⢿⣷⣏⣏⡛⣏⠒⣀⣀⣀⣀⣀⣀⣀⡲⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⢸⠒⠄⠄⠄⠄⠛⣀⣀⣀⣀⠤⠲⣮⣏⡇⠒⣀⣀⣀⠤⣀⢿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠛⣾⣷⣭⣮⣭⣭⡏⣥⣭⣭⣭⣭⡛⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣮⡾⡛⣏⡛⡛⡛⣏⡇⠤⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣮⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠤⡲⠄⠄⠒⣀⣀⣀⣀⣮⣾⠄⠄⠄⠄⢿⠲⢃⣀⣀⣀⣀⡾⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣭⣭⢸⣥⣭⢸⣭⣭⢸⣝⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⢿⡛⡏⡛⣾⣏⣏⠒⠒⠒⠤⠤⠤⣥⣀⠤⠤⣀⣀⣀⣀⣀⣀⣀⠤⠤⠲⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣥⣀⣀⣀⣥⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢃⣀⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⡾⣭⣭⣮⢿⣮⣭⣮⡏⣭⣭⢸⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣭⣾⢸⢸⢸⢸⡏⣏⢸⠒⠤⠤⣾⠤⠤⠤⠤⠤⠒⠒⢃⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣮⣮⣀⢸⠛⢃⠤⠒⠄⣀⣀⡾⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣫⣀⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⣭⣭⣭⣭⣭⣭⠄⣮⢿⢿⢿⣮⣮⡾⣮⣭⢿⣾⣭⡇⡇⡇⡇⡇⢸⡇⢸⢸⡏⠤⠤⠤⢘⠒⠤⠤⠤⠤⠤⢘⠤⠤⠤⠤⢃⢃⢃⣀⣀⣀⣀⣀⣀⠒⣀⣀⣀⣀⣀⣀⣀⣀⠄⠒⡏⣀⣀⣀⣀⣀⣀⣀⡛⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡾⣀⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣥⣭⣭⣭⣭⢿⠄⠄⠄⢃⡲⡲⠛⠛⠛⠛⢘⢘⣥⢘⢘⢘⡇⡇⢃⢃⣭⠒⠤⠤⠤⠤⠤⠤⠒⠒⠤⠤⠤⠤⠒⠒⠒⠤⠤⣀⣀⣀⣀⠄⡾⠒⣀⣀⠤⢃⢃⢃⣀⣀⣀⣀⣀⣀⠤⢃⠤⠤⣀⠤⠤⠤⣀⣀⣥⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⣀⣀⣀⡛⣀⠄⠄⠄⠄⠄⠄⠄⠄
⢸⣥⣭⣭⠤⠄⠄⠄⠄⠲⡲⣝⡲⠛⡲⡲⡲⣷⠛⠒⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠒⠒⠒⠤⠤⠤⠤⠤⠒⣫⣀⣀⠒⠤⣀⣀⣀⣀⣀⣀⢃⢃⢃⢸⢃⣀⣀⣀⣀⣀⢸⠒⠤⠤⠤⠤⠤⠤⠤⠤⡛⠲⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⣀⣀⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⢃⣮⠄⠄⠄⠄⠄⠄⡇⣀⡏⣀⣀⣀⣀⣀⠒⣏⠤⠤⠤⠤⠤⠤⠤⡲⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⣀⠒⠒⠤⠒⣀⣀⠤⢿⡛⢃⢃⠒⠒⢃⠒⠒⠒⠤⠒⠤⠒⠲⢃⢃⣀⣀⣀⣀⠒⠤⠤⠤⠤⠤⠤⠤⢃⢘⢃⢃⠒⢘⣭⠄⠄⣝⣀⣀⣀⣀⣀⣥⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⣝⣀⠒⢿⣀⣀⣀⣀⣀⡾⠤⠤⠤⠤⠤⠤⠤⠤⣏⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⡲⠛⢃⢃⢃⢃⠤⠛⡏⠲⠤⠤⠤⠤⠤⠒⣾⢘⠤⠤⠒⠒⢃⠒⠤⣀⣀⠄⠲⠤⠤⠒⢃⠒⢸⣥⣏⡛⠛⠛⠒⢃⣀⣀⣀⣀⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⣀⣀⣏⠒⣀⣀⣀⣀⣀⢿⣀⣀⠤⠤⠤⠤⠤⠤⠛⠤⠤⠤⠤⠤⠤⣀⣀⢃⢃⢃⢃⣥⠛⢃⢃⠒⠤⠤⠤⠒⣝⡇⠤⠤⠤⠤⢸⣀⣷⡛⠒⠤⣫⠤⠒⠤⠒⠒⢃⢃⠲⡛⠛⠛⠛⣮⡲⡇⣮⡛⡛⡛⠲⣏⡾⡾⡾⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⡾⣀⡏⣀⣀⣀⣀⣀⣀⢸⡾⣀⣀⣀⢃⢃⢃⣀⣀⠤⢃⢃⢃⢃⢃⢃⢃⢃⢃⢃⢃⢃⢃⢿⡲⢃⠤⠤⠤⠤⠒⣭⠲⡲⠤⣥⠤⠤⣥⠤⡾⠒⠤⠤⠒⠒⠒⠒⠒⠒⣾⡲⢃⢃⠒⠒⠲⠲⠲⡾⠛⠲⣀⣀⣀⣀⣀⢃⣮⣝⠛⡲⣏⣮⢃⠤⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⣀⣀⣏⣝⣀⣀⣀⣀⣀⢿⣥⠤⣀⠒⢃⢃⢃⢃⢃⢘⡲⢃⢃⢃⢃⢃⠒⠤⠤⠤⠤⠤⠤⠤⠛⣏⠒⠤⠤⠤⠤⠤⣮⠒⡛⠒⠤⠒⠤⢃⠤⣫⠤⠤⡾⠤⠒⠒⢃⢃⠒⠒⢃⢃⢃⡲⣀⠲⠲⢘⠄⢸⠛⣥⠤⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⣀⣀⣫⣀⣀⣀⣀⣀⣀⣝⣏⠒⢃⢃⢃⢃⢃⢃⠤⠒⣫⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⢿⠛⠒⠤⠤⠤⠤⠤⠒⠲⣀⣀⣭⠤⠤⠒⣾⣏⡏⠒⠤⠒⠒⠤⠤⠒⠒⠒⠒⢃⡏⢃⢃⣀⣀⡾⠄⣀⠄⣫⠛⠛⣏⠒⠤⣀⠄⣀⢿⠄⠄⠄⠄⠄⠄⣀⠄⣥⠄⠄
⠄⠄⠄⠄⠄⡾⣀⠤⠄⣀⣀⣀⣀⣀⣀⣥⣥⢃⢃⢃⠤⠤⠤⠤⠤⠤⣏⠒⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠒⠛⡇⠤⠤⠤⡏⠤⠤⢿⣀⣀⣀⠤⠲⠲⡇⡇⡇⠤⠤⢿⠒⠤⠤⠤⠤⠒⠒⢘⣏⢃⢃⠤⣀⣀⠄⠄⠄⠄⣀⠄⢘⣭⠛⠛⠛⣥⣫⠲⠛⣀⣀⣀⠄⣀⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠲⣀⣀⠤⣏⣀⣀⣀⠄⠛⡾⡏⢃⢃⠤⠤⡇⠤⠤⠤⠒⠲⡛⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⣝⠛⡲⠒⠤⣏⠤⠤⠒⣀⣀⣀⣀⣀⢃⢃⢃⡇⣾⠤⠒⠤⠤⢿⠤⠤⠒⣾⠒⠒⢃⢃⢃⢸⣫⣭⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⣫⣏⠄⠄⣀⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⣀⣀⠒⣮⡾⣀⣀⣀⣀⠛⡾⡇⢃⢃⠤⠤⣝⠤⠤⠤⠤⢘⡏⣮⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⣥⠛⢿⠒⠒⠛⢸⢃⠒⠤⠤⣀⣀⣀⣀⣀⣀⣝⡾⠤⠤⢃⠒⢘⣭⣭⣀⠄⠤⣥⢃⢃⢃⡛⢃⣀⣫⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⣀⣀⡲⡏⣥⠄⡇⣮⣮⡇⠛⡲⢃⢃⠤⠤⠤⠒⠒⠤⠤⣮⠲⡏⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠒⠛⢿⠒⢃⢃⠲⢃⣮⣫⣀⣀⣀⣀⣀⢃⠲⣀⢃⠤⠒⡾⣾⣏⠤⢿⠒⣀⣀⢃⢃⢃⣫⢿⣾⣏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⣀⣀⠲⠤⣮⣀⠤⣀⠤⡲⠲⠛⣭⢃⠒⠒⠒⡾⠤⠤⠤⠒⠲⣀⠛⠒⠤⠤⠤⢃⠤⠤⠤⠤⠤⠒⠒⠛⣏⢃⢃⢃⣏⡾⢃⡾⣀⢸⣀⠒⢸⣷⢿⣝⡾⡾⢸⠲⠲⣀⣀⣀⣀⣀⣀⣀⡾⢃⠛⢸⢃⠤⣝⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⡛⣀⣀⣀⠛⣀⣀⠤⣀⡾⣭⣝⣭⢃⠒⠒⠒⣮⠤⠤⠤⠤⠲⣀⣀⢃⢃⢃⠒⠒⠒⠒⠒⢃⢃⢃⢸⠛⢸⢃⢃⢃⠛⠲⠲⣥⣀⢃⢿⣾⣥⢿⣷⣷⣾⠤⢃⣏⠲⣀⣀⣀⣀⣀⣀⣀⡾⠒⢃⢃⢃⠤⠤⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⡇⣀⣀⣀⠄⣀⣀⢃⡇⡲⢿⣭⣏⢿⠒⠒⠒⠛⣏⠒⠒⠒⡲⣀⣀⣀⠲⠲⠲⢃⢃⡛⢃⢃⢃⢃⣮⢿⠒⢃⢃⢃⠲⠲⢃⢃⣥⣾⣀⠒⣮⣾⣭⣾⣝⠄⢃⠒⠲⣀⣀⣀⣀⣀⠛⣀⠛⣏⢃⢃⢃⢃⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠤⣀⣀⠄⣫⠤⢃⢃⠲⢃⢃⢿⠛⠒⠤⠒⠒⣏⢃⠤⠒⠤⣮⣀⣀⣀⠒⢿⠒⠲⠲⣮⠒⠒⢃⠛⢘⢃⢃⢃⢃⠲⢃⢃⣀⣏⠒⠒⣭⡏⡛⡏⢸⡏⠄⠛⠛⣭⣀⣀⣀⣀⠒⣀⡾⣏⣥⢃⢃⢃⢃⣀⡾⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⡾⣀⣀⠄⠄⠒⢃⢃⢃⢃⢃⢃⠛⡏⠒⠒⠤⡾⠲⢃⡏⠤⠒⠤⣀⣀⣀⣀⢃⡲⠲⠲⡲⢃⡏⣏⢃⢃⢃⢃⣮⠲⣫⡲⣀⠤⠄⣀⣀⣏⢸⢸⣮⠲⠄⣮⢃⡾⠤⣀⠤⠤⠤⠛⣏⠒⠤⠒⢃⢃⢃⠒⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢸⠲⡲⠄⡾⢃⢃⢃⢃⢃⢃⠛⡲⢿⠤⢃⠒⠲⢃⠲⠲⠒⠤⠲⣀⠤⣀⣀⣀⢘⣭⢃⢿⢃⠲⠲⢿⢃⠒⢃⢃⡇⠄⣀⠄⣀⣀⣀⠤⠤⠤⠤⠤⠤⠒⢃⣮⣀⣀⣷⣀⣫⠲⠤⠤⠤⣝⢃⢃⢃⢃⣀⡾⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⣮⢸⠄⠄⠤⢃⢃⢃⠒⢃⠒⢿⢘⡾⠒⠤⡲⠲⣀⠲⠲⢃⣮⢃⣀⠤⣀⣀⣀⣀⠒⠲⠲⡏⡛⣝⠲⠲⠲⢘⣀⡇⣝⣏⡲⣀⠤⠤⠤⠤⠤⠤⠤⠤⢃⡾⠤⣝⣏⣏⡇⠒⠤⠤⠤⣫⢃⢃⢃⢃⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⣀⡲⣿⡲⣀⣥⠒⢃⢃⠒⠛⣿⠛⢿⡲⡇⠤⡾⢃⣀⣀⣀⣀⠲⠲⠤⣀⣀⣫⡾⢃⠤⣀⠲⠲⡾⢃⣀⣀⠒⣀⣀⣀⣀⣀⣀⣀⣀⠤⠤⠤⠤⠤⠤⠤⢃⣾⡲⣥⣏⢸⣭⣷⠤⠤⠤⣮⡲⢃⢃⢃⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⣿⣀⣀⣀⠄⣥⢘⣾⠒⢃⢃⢃⠒⢃⣏⡛⡲⣮⠤⣏⣥⣀⢿⡾⣾⢿⡇⡾⠲⠤⠤⠤⣀⠄⣝⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠤⠤⠤⠤⠤⣀⢃⢿⢘⣫⣏⣾⣭⣭⣾⠤⠤⠤⢿⠲⢃⢃⣀⣀⣀⣏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⣀⣏⣀⠄⠄⠄⠛⡇⡛⡾⡲⣮⠒⢃⢃⢃⠒⠒⣏⠒⡲⣮⣏⣏⣥⢿⣀⣀⣀⠤⠤⠤⠤⠤⠤⠤⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⢃⡏⡲⣮⣏⢿⣮⣭⣭⢸⠤⠤⡏⠲⠲⠲⢃⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⡛⡏⡲⡲⣾⠒⢃⢃⠒⠒⠒⣏⠒⡛⢘⡾⣏⡾⣀⢿⠤⠤⠤⠤⠤⠤⠤⠤⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡛⠒⡲⡲⡾⡛⢿⢿⣭⣝⣫⠤⠒⣭⣮⠲⢃⠲⢃⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⣿⡛⣥⣷⠄⠄⠄⠄⠄⢿⢃⡲⢃⡲⢿⠛⢃⢃⢃⠒⠒⠒⡛⠒⢃⡲⣥⡏⠤⣥⠲⠤⠤⠤⠤⠤⠤⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠤⣏⢃⠒⠛⡲⢿⣝⠒⠤⠤⠤⠤⠤⠤⣝⠛⠲⠲⡲⢃⢃⣀⣀⠤⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⢘⣷⠒⠄⠄⠄⠄⠄⠄⣥⢘⣫⢃⠲⣏⣏⡲⢃⢃⢃⠒⠒⠒⣥⠒⠒⠤⡲⢿⣝⡲⡛⣀⠤⠤⠤⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡲⣀⠄⣀⣀⣀⣀⣀⣀⣮⠲⢃⢸⠒⡲⡲⣾⠛⠤⠤⠤⠤⠤⠤⠤⢃⡲⠲⠲⠲⠲⡾⢃⣀⠤⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⣀
⠄⠤⠄⠄⠄⠄⠄⠄⠄⠄⡲⣏⢃⡇⡾⡲⠛⡛⠛⣝⠒⢃⠒⠒⠒⡲⠒⠒⠒⠤⣾⡇⠛⡲⣏⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠄⣀⣀⣀⣀⠄⣀⠒⢃⢃⠒⣝⡛⡲⡲⣭⠤⠤⠤⠤⠤⠤⠤⠤⠤⠒⢃⠲⠲⠲⠲⡛⢃⣀⣀⣀⠄⠄⠄⠄⠄⠄⠄⣀⣀⣀⣀⣀⣀⣀
⠄⠄⠄⠄⠄⠄⠄⠄⠄⣮⢃⡇⣫⠛⡲⡲⡲⢿⡲⡲⡲⣝⢃⠒⢃⠒⠒⠒⠒⠒⡛⡲⡲⢘⡾⡲⡲⡾⣥⣀⠤⠄⣀⠄⣀⣀⣀⣀⣀⣀⣀⣀⣀⠄⣀⠒⢃⢃⢃⣀⣀⡲⡛⡲⡲⡇⠤⠤⠤⠤⠤⠤⠤⠤⠤⡲⠤⠤⠲⠲⠲⠲⢸⣝⣀⣀⣀⡏⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀
⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⢃⢃⢘⣏⣫⠛⣮⡲⣥⢃⡲⡲⢿⡲⠒⢃⢃⠒⡛⠒⠒⡲⡲⡲⡲⡲⠛⡲⠛⡲⡲⠄⣝⣏⡲⡲⡲⡲⡛⠒⠒⠒⠒⠒⠒⢃⢃⢃⣀⣀⡏⠛⣫⡏⡲⡲⠤⠤⠤⠤⠤⠤⠤⠤⠤⣮⠤⠤⠤⠲⠲⠲⡲⢘⢘⣀⣀⠄⣮⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀
⠄⠄⠄⠄⠄⠄⠄⠄⡲⠤⢃⢿⡛⡲⡇⢸⡲⣮⣭⠛⢃⢃⠛⡛⡲⡲⡏⢃⢃⢃⠲⡾⡲⡲⡲⡲⡲⡲⡲⡲⡲⣥⠄⡾⣏⡲⡲⣾⣭⠒⢃⢃⢃⢃⢃⢃⢃⣀⠤⣮⠲⠛⠛⠛⢘⡲⠤⠤⠤⠤⢃⠤⠤⠤⠤⢿⠤⠤⠤⠤⠲⠲⠲⡲⡲⡲⣀⣀⠄⠲⡾⡛⠒⠤⣀⣀⣀⣀⣀⣀
⠄⠄⠄⠄⠄⠄⠄⠄⣀⣀⣥⣏⡲⡲⡲⡲⠛⣏⣏⢃⢃⣭⢃⢃⠒⡲⡲⡲⡲⡲⢃⣾⡏⡲⡲⠛⢿⡏⡲⡲⡲⣫⠄⠄⡛⠲⠛⠛⠛⢿⢃⠒⢃⢃⢃⣀⣀⡇⠛⣝⢘⠛⠛⠛⠛⠛⠤⠤⠤⠤⢃⠤⠤⠤⠤⣝⠤⠤⣝⡾⠛⢃⠒⣀⣀⠛⡛⣀⠤⠤⣾⠲⣝⡏⡇⣮⣀⣀⣀⣀
⠄⠄⠄⠄⠄⠄⠄⣫⣀⡾⢿⡲⡲⡲⡲⡲⡲⣥⠒⢃⢃⢃⡛⠛⠒⣭⢃⢃⢃⢃⢃⠲⡲⡲⡲⡲⡲⡲⡲⡲⡲⡏⣀⠄⣭⠛⠛⠛⢘⠛⠛⠛⢘⡇⣏⢘⠛⠛⣝⠛⠛⠛⠛⠛⠛⠛⠤⠤⠤⠤⠤⠤⠤⠤⠤⣫⢃⢃⢃⣀⣀⣀⣀⣀⣀⣀⣀⣀⡇⠤⠤⣀⠲⡏⢿⢸⡇⠛⣮⣀
⠄⠄⠄⠄⠄⠄⣝⣥⣀⢿⢘⡲⡲⡲⡲⡲⡲⣫⠤⠒⢃⢃⢿⣭⠒⡏⠲⣥⢃⢃⢃⢃⠒⢃⢃⢃⢃⢃⢃⢃⢃⢃⢃⢃⣥⠛⠛⠛⠛⠛⠛⣥⢘⠛⠛⠛⡇⣏⠛⠛⠛⠛⠄⡲⠛⠛⢃⠤⠒⠒⠒⠤⠤⠤⠤⣭⢃⢃⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠲⣀⣀⣀⠤⢿⡇⡇⢘⠛
⠄⠄⠄⠄⠄⠄⣀⣀⣮⣏⡲⡲⡲⡲⡲⡲⡲⠲⠤⢘⢃⠛⣏⢸⠒⢃⢃⢃⢃⢃⢃⢃⣫⠲⢃⢃⢃⢃⢃⢃⢃⢃⢃⢃⠲⠛⠛⠛⠛⢘⠛⣥⠛⠛⠛⠛⠛⢘⠛⠛⢘⠄⠄⠄⠛⣫⡇⠤⠒⣭⢃⠤⠤⠒⠤⣾⢃⢃⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠒⣀⣀⣀⣀⣀⠛⠛⡲
⠄⠄⠄⠄⠄⠲⣀⣮⡇⡲⡲⡲⡲⡲⡲⡲⡲⠒⠤⢘⢃⣭⣏⠲⢃⢃⢃⡛⢃⢃⢃⢃⠒⢘⢃⢃⢃⢃⢃⢃⠲⠲⠲⠲⡇⢿⡲⠛⠛⠛⡛⡛⣥⣾⣥⢘⡛⡛⣥⠛⣀⠄⠄⠄⠒⢿⠒⠒⢃⠲⠲⠤⠤⠒⡲⣫⢃⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠤⠤⣀⣀⣀⣀⣀⣀
⠄⠄⠄⠄⡾⣀⣮⠄⣏⡲⡲⡲⡲⡲⡲⡲⣏⠤⠤⠒⢃⡾⢿⢃⢃⢃⢃⠛⢃⢃⢃⢃⣮⠤⡲⠲⢃⢃⠲⠲⠲⠲⠲⡛⢿⣭⣾⢘⢘⡾⣫⡛⣥⣥⣥⣥⣥⡛⡛⣝⣏⠄⣀⠄⣫⠤⠤⠤⢸⠲⠤⠤⠒⠲⡇⠲⢃⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡇⣀⣀⣀⣀⣀⣀⣀
⠄⠄⠄⠄⣀⣏⠄⠄⡲⡲⡲⡲⡲⡲⡲⡲⣮⠤⠤⠤⠤⡾⣥⢃⣭⢃⢃⣏⠛⢃⢃⢃⢃⠲⡾⣮⢃⠲⠲⠲⠲⠲⣝⡾⢿⣝⣝⠄⣝⣝⣝⣥⣥⡛⠛⠛⡇⣥⣾⣝⣝⣾⠄⣝⣝⠤⠒⢃⡲⠤⠤⠤⠒⢿⠛⠲⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡾⣀⣀⣀⣀⣀⣀
⠄⠄⠄⣀⡾⠄⠄⣥⡲⡲⡲⡲⡲⡲⡲⡲⡾⠤⠤⠤⠤⡾⢸⢃⠤⢃⢃⡛⡾⢃⢃⢃⢃⠒⠲⢃⢃⣾⢃⠲⠲⡲⢿⡾⣝⣝⣝⣮⣝⣝⣝⣏⠛⠛⠛⠛⠛⡲⣝⡏⡏⡏⡏⣝⠲⠒⢃⣏⢃⠒⠤⠒⠒⣏⢿⠲⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣥⠤⣀⣀⣀⣀
⠄⣀⡇⣫⠄⠄⠄⣏⡲⡲⡲⡲⡲⠲⢿⡲⡛⠤⠤⠤⠤⣮⣭⢃⣀⢸⠲⡛⡛⣮⢃⢃⢃⢃⡲⠒⠒⠲⠲⠲⠛⡾⣮⣝⣫⣝⣝⣝⣝⣝⣝⣮⠛⠛⠛⠛⠛⣝⡏⡏⡏⡏⡏⢿⠤⠒⣝⢘⠤⠤⢃⠒⠒⣏⣏⣀⠲⢃⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠤⢃⣝⣀⣀⣀
⠄⡾⡾⠄⣀⣀⣀⡲⡲⡲⡲⡲⡲⢿⠤⡲⡲⠤⠤⠤⢃⡏⣝⠄⣀⠤⢃⢃⣏⡛⣥⢃⢃⢃⠒⣮⣀⣀⣀⠄⢿⡾⡏⡏⡏⡏⡏⡏⡏⡏⡏⡾⡇⡏⣥⢸⡇⡾⡏⡏⡏⡏⣫⠤⣀⣝⢘⠤⠤⠒⠒⢃⣏⡛⠲⠲⠲⡇⠤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡏⠄⣀⢿⣀
⣀⡾⠤⣀⣀⣀⣏⡲⡲⡲⡲⡲⠲⠤⠤⣫⡲⠤⠤⠤⣀⣏⠒⣀⣀⠄⠤⠒⠛⡇⡏⣾⢃⢃⢃⢃⡇⣀⣀⣭⣮⡏⡏⡏⡏⡏⡏⡏⡏⡏⣾⠛⠛⠛⣏⡛⠛⠛⡏⡏⣝⣮⠲⣝⣝⠤⠤⠤⠒⠒⠒⡏⣾⢿⠤⠲⠲⢘⠲⠒⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⢘⢘⣀⠄⠄⣮⣀⣀

    启铭星
    qq:604223110
    骂谁钢板.mp3
*/

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<ll> rd(1e8,1e9);
std::default_random_engine e;
ll mod=998244353;
ll T=1;
ll INT=std::numeric_limits<ll>::max();
ll INTT=std::numeric_limits<ll>::min();
ld eps = 1E-8;

cas(Hiyori,l i,AC(v,alona))(ll x){iroha x==1?1:(ll)(mod-mod/x)*inv(mod%x)%mod;}ll ksm(ll a, ll b){ll res=1;while(b){if(b&1){res=(res*a)%mod;}a=a*a%mod;b>>=1;}iroha res%mod;}
void sa(bool ok){if(ok)pt(yes);lf(ok)pt(no);pt(\n);}void SA(bool ok){if(ok)pt(YES);lf(ok)pt(NO);pt(\n);}void Sa(bool ok){if(ok)pt(Yes);lf(ok)pt(No);pt(\n);}
void prepre(int n){
    // AC(pen,cas(fr,Murakasa,Mizuha))(ms(.ca(Utazumi,alona)), ms(Kayoko), ca(st,ca(Natsu,in)));
    // AC(pen,cas(fr,Murakasa,Mizuha))("data.out", ms(w), stdout);
    // std::cin>>T;
    std::cout<<std::fixed<<std::setprecision(12);
}
ca(l,l Hakari)[1145141];
ca(l,l n),m,tot;
ca(Hiyori,l) ca(m,AC(d,i)),l[214514],r[214514],w[214514];
ll ans,anss;
ll k;
std::string s,ca(s,s);
vvpll v;
std::map<pll, int> ma;
bool vie[214514];
struct takina{
	int u ,v ,w ,id;
	bool operator <(const takina& B)const{return w < B.w;}
}E[414514]; int ff[414514];
bool cmp(takina a ,takina b){return a.id < b.id;}
int find(int x){return ff[x] == x ? x : ff[x] = find(ff[x]);}

namespace LCT{
	#define lch(x) ch[x][0]
	#define rch(x) ch[x][1]
    #define MX 414514
	int ch[MX][2] ,fa[MX] ,mx[MX] ,key[MX] ,rev[MX];
	int get(int x){return x == ch[fa[x]][1];}
	int Nroot(int x){return get(x) || x == ch[fa[x]][0];}
	void init(){key[0] = mx[0] = -1e9;}
	void pushup(int x){mx[x] = std::max(std::max(mx[lch(x)] ,mx[rch(x)]) ,key[x]);}
	void dorev(int x){std::swap(lch(x) ,rch(x)) ,rev[x] ^= 1;}
	void pushdown(int x){if(rev[x]) dorev(lch(x)) ,dorev(rch(x)) ,rev[x] = false;}
	void rotate(int x){
		int f = fa[x] ,gf = fa[f] ,which = get(x) ,W = ch[x][!which];
		if(Nroot(f)) ch[gf][get(f)] = x; ch[x][!which] = f ,ch[f][which] = W;
		if(W) fa[W] = f; fa[f] = x ,fa[x] = gf ,pushup(f);
	}int stack[MX] ,dep;
	void splay(int x){
		int f = x; stack[++dep] = f;
		while(Nroot(f)) stack[++dep] = f = fa[f];
		while(dep) pushdown(stack[dep--]);
		while(Nroot(x)){
			if(Nroot(f = fa[x])) rotate(get(x) == get(f) ? f : x);
			rotate(x);
		}pushup(x);
	}
	void access(int x){
		for(int y = 0 ; x ; x = fa[y = x])
			splay(x) ,rch(x) = y ,pushup(x);
	}
	void makeroot(int x){access(x) ,splay(x) ,dorev(x);}
	void split(int x ,int y){makeroot(x) ,access(y) ,splay(y);}
	void link(int x ,int y){makeroot(x) ,fa[x] = y;}
    #undef MX
	#undef lch
	#undef rch
}using namespace LCT;

/*必须包含某一条边*/

NAME MeIoN_is_UMP45(){
    std::cin >> n >> m;
    init();
    F(i,m){
        meion &[u,v,w,id]=E[i];
        std::cin>>u>>v>>w;
        id = i;
    }
    F(i,n){
        ff[i] = i,key[i]=-100000000;
    }
    std::sort(E + 1, E + 1 + m);
    ll S = 0;
    F(i,m){
        meion & [ u, v, w, id ] = E[i];
        key[i + n] = w;
        if(find(u)==find(v)){
            continue;
        }el{
            ff[find(u)] = find(v);
            link(u, i + n), link(i + n, v), S += key[i + n];
        }
    }
    std::sort(E + 1, E + 1 + m, cmp);
    F(i,m){
        meion & [ u, v, w, id ] = E[i];
        split(u,v);
        std::cout << S - mx[v] + w << endl;
    }
}                                                                                                                                                                                                                                                                                       cas(Utazumi,n,miku)ca(schale(hina),alona)(){hello_world();prepre(114514);iori(_,T)AC(as,Yutori)(AC(AC(N,Mizuha),cas(M,Murakasa,I)),cas(_,ca(Utazumi,Hatsune),_),UMP45)();}