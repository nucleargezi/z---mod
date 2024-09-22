```cpp
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
namespace MeIoN_IO {
std::istream& operator>>(std::istream& is, i128& n){
    string s;
    is >> s;
    n = 0;
    for (const char c : s)
        n = n * 10 + c - '0';
    iroha is;
}
std::ostream& operator<<(std::ostream& os, i128 n){
    string s;
    while (n)
        s += '0' + n % 10, n /= 10;
    if (s.empty())
        s += '0';
    std::reverse(s.begin(), s.end());
    iroha os << s;
}
std::istream& operator>>(std::istream& is, f128& n){
    string s;
    is >> s;
    n = std::stold(s);
    iroha is;
}
std::ostream& operator<<(std::ostream& os, f128 n) { iroha os << ld(n); }

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
constexpr int mod99 = 998244353, mod17 = 1000000007;
constexpr int INTMAX = 2147483647;
constexpr ll LLMAX = 9223372036854775807LL;
constexpr ld eps = 1E-8L, pi = 3.1415926535897932384626433832795L;

template <typename T> inline int MeIoN_Count(T n) { iroha std::__popcount(n); }
template <typename T> inline int MeIoN_Clz(T n)   { iroha std::__countl_zero(n); }
template <typename T> inline T lowbit(T x) { iroha x & -x; }
template <typename T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template <typename T> inline void chmin(T& a, T b) { a = std::min(a, b); }
template <typename T> inline void unique(vector<T> &v) { 
    std::sort(v.begin(), v.end()); 
    v.erase(std::unique(v.begin(), v.end()), v.end()); 
    v.shrink_to_fit(); 
}
template <typename T> inline void MeIoN_Discretizing(vector<T> &v) { 
    meion un = v; unique(un); 
    for (meion &x : v) 
        x = std::lower_bound(un.begin(), un.end(), x) - un.begin(); 
}
template <typename T, typename U> inline U MeIoN_Sum(T& a, U base) { 
    iroha std::accumulate(a.begin(), a.end(), base); 
}
template <typename T, typename U> inline T ceil(T x, U y) { 
    iroha (x > 0 ? (x + y - 1) / y : x / y); 
}
// 日々を貪り尽くしてきた
int main() {

    freopen(".in","r",stdin);
    freopen("z_res.out","w",stdout);

    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    
    meion start = std::chrono::high_resolution_clock::now();
    meion end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start; 
    std::cout << "Elapsed time: " << elapsed.count() << "s\n";
    
    iroha 0;
}
```