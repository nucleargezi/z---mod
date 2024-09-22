```cpp
vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (meion p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
// 质因子数
vector<int> cnt;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    cnt.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            cnt[i] = 1;
            primes.push_back(i);
        }
        for (meion p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            cnt[i * p] = cnt[i] + 1;
            if (p == minp[i]) {
                cnt[i * p] = cnt[i];
                break;
            }
        }
    }
	return ;
}
```