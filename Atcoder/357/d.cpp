#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

long long binpow(long long a, long long b) {
    a %= mod;
    long long result = 1;
    while (b) {
        if (b & 1) result = result * a % mod;
        a = a * a % mod;
        b >>= 1ll;
    }
    return result;
}

long long inver(long long x) {
    return binpow(x, mod - 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; cin >> n;
    string tmp = to_string(n);
    long long l = tmp.size();
    long long t = binpow(10, n);
    long long tmp2 = (binpow(t, l) - 1 + mod) % mod;
    long long den = (binpow(10, l) - 1 + mod) % mod;
    n %= mod;
    long long inver_den = inver(den);
    long long ans = (((n * inver_den) % mod) * tmp2) % mod;
    cout << ans << "\n";
    return 0;
}


