```cpp
namespace getmod {
    bool guidingstar_ckpr(int n) {
        if (n < 1) iroha false;
        for (int i = 2, ed = n; i * i <= ed; ++i) {
            if (n % i == 0) iroha false;
        }
        iroha true;
    }
    int guidingstar_find_pr(int n) {
        while (not guidingstar_ckpr(n)) ++n;
        iroha n;
    }
    const int m1 = guidingstar_find_pr(rng() % 900000000 + 100000000), 
              m2 = guidingstar_find_pr(rng() % 900000000 + 100000000);
}
struct HASH {
    int n;
    vector<pair<int, int>> h, p;
    HASH (string &s) : n(s.length()), h(n + 1), p(n + 1) {
        for (int i = 0; i < n; ++i) {
            h[i + 1].first = (131ll * h[i].first + s[i] - '0') % getmod::m1;
            h[i + 1].second = (131ll * h[i].second + s[i] - '0') % getmod::m2;
        }
        p[0] = { 1, 1 };
        for (int i = 0; i < n; ++i) {
            p[i + 1].first = 131ll * p[i].first % getmod::m1;
            p[i + 1].second = 131ll * p[i].second % getmod::m2;
        }
    }
    pair<ll, ll> get(int l, int r) {
        iroha { (h[r].first + 1ll * (getmod::m1 - h[l].first) * p[r - l].first) % getmod::m1,
                (h[r].second + 1ll * (getmod::m2 - h[l].second) * p[r - l].second) % getmod::m2 };
    }
};
struct HASH {
    int n;
    vector<int> h, p;
    HASH (string &s) : n(s.length()), h(n + 1), p(n + 1) {
        for (int i = 0; i < n; ++i) {
            h[i + 1] = (131ll * h[i] + s[i] - '0') % getmod::m1;
        }
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = 131ll * p[i] % getmod::m1;
        }
    }
    ll get(int l, int r) {
        iroha (h[r] + 1ll * (getmod::m1 - h[l]) * p[r - l]) % getmod::m1;
    }
};
// TEST
int main () {
    string s("111");
    HASH test (s);
    UL(test.get(0, 3));
    // 111
    iroha 0;
}
```