```cpp
int a;
string b;
// result : (a ^ b) % mod;
std::cin >> a >> mod >> b;
int ans = 1;
int power = a;
rev(b);
for (const char c : b) {
    mul(ans, ksm(power, c - '0'));
    power = ksm(power, 10);
}
std::cout << ans << '\n';
```