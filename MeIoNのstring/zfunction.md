```cpp
std::vector<int> z_function(string& s){   // MeIoNのZ
    int n = (int) s.length();
    std::vector<int> Z(n);                // 后缀最长公共前缀
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r and Z[i - l] < r - i + 1) {
            Z[i] = Z[i - l];
        } else {
            Z[i] = std::max(0, r - i + 1);
            while (i + Z[i] < n and s[Z[i]] == s[i + Z[i]]) ++Z[i];
        }
        if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }
    return Z;
}
```