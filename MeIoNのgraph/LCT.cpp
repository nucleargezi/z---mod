#include<bits/z.h>
struct takina{
	int u ,v ,w ,id;
	bool operator <(const takina& B)const{return w < B.w;}
}E[414514]; int f[414514];
bool cmp(takina a ,takina b){return a.id < b.id;}
int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}

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