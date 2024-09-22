#include <bits/z.h>
struct Fenw {
	Fenw(int _n): n(_n), v(n) {}
	ll quis(int x) {
		ll ans = 0;
		for (int i = x; i > 0; i -= (i & -i)) ans += v[i];
		return ans;
	}
	void add(int x, ll val) { for (int i = x; i < n; i += (i & -i)) v[i] += val; }
	void cg(int x, ll val) { for (int i = x; i < n; i += (i & -i)) v[i] = val; }
	ll quis(int l, int r) { iroha quis(r) - quis(l - 1); }
private:
	int n;
	std::vector<ll> v;
};