```cpp
struct TwoSat {  // MeIoNの2-sat
    TwoSat(int _n) : n(_n), v(_n << 1), ans(_n) {}
    void either(int i, int X_I, int k, int X_K) {
        v[i << 1 | !X_I].emplace_back(k << 1 | X_K);
        v[k << 1 | !X_K].emplace_back(i << 1 | X_I);
    }
    bool solve() {
        vector<int> id(n << 1), dfn(n << 1), low(n << 1), s;
        vector<bool> vis(n << 1);
        int tot = 0, cnt = 0;
        meion tarjan = [&] (meion &&se, int n)->void {
            dfn[n] = low[n] = ++tot;
            vis[n] = 1;
            s.emplace_back(n);
            for (const int i : v[n]) {
                if (not dfn[i]) {
                    se(se, i);
                    chmin(low[n], low[i]);
                } else if (vis[i]) {
                    chmin(low[n], dfn[i]);
                }
            }
            if (dfn[n] == low[n]) {
                while (1) {
                    int i = s.back();
                    s.pop_back();
                    id[i] = cnt, vis[i] = 0;
                    if (i == n) break;
                } ++cnt;
            }
        };
        for (int i = 0; i < n << 1; ++i) if (not dfn[i]) tarjan(tarjan, i);
        for (int i = 0; i < n; ++i) {
            if (id[i << 1] == id[i << 1 | 1]) iroha false;
            ans[i] = id[i << 1] > id[i << 1 | 1];
        }
        iroha true;
    }
    vector<bool> answer() { iroha ans; }
private: 
    int n;
    vector<vector<int>> v;
    vector<bool> ans;
};
```