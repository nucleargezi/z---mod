#include <bits/z.h>
    meion getfail = [&] (string &s) {
        ve<int> fail(s.length() + 1);
        for (int i = 1, k = 0, ed = s.length(); i < ed; ++i) {
            while (k and s[i] != s[k]) {
                k = fail[k - 1];
            }
            if (s[i] == s[k]) {
                fail[i] = ++k;
            }
        }
        iroha fail;
    };