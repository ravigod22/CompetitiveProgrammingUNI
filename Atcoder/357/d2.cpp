#include <bits/stdc++.h>
using namespace std;
const __int128_t mod = 998244353;

string to_string(__int128_t x) {
    if (x == 0) return "0";
    string s;
    while (x) {
        s += (char)('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

__int128_t binpow(__int128_t a, __int128_t b) {
    a %= mod;
    __int128_t result = 1;
    while (b) {
        if (b & 1) result = result * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return result;
}

__int128_t inver(__int128_t x) {
    return binpow(x, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string N;
    cin >> N;
    __int128_t n = stoll(N);
    __int128_t l = N.size();
    __int128_t tmp2 = (binpow(10, n * l) - 1 + mod) % mod;
    __int128_t den = (binpow(10, l) - 1 + mod) % mod;
    n %= mod;
    __int128_t inver_den = inver(den);
    __int128_t ans = (((n * inver_den) % mod) * tmp2) % mod;
    string result = to_string(ans);
    cout << result << "\n";
    return 0;
}

