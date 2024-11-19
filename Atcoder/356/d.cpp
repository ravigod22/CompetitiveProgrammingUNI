#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
const long long mod = 998244353;

long long fact[maxn];
long long inv[maxn];

long long binpow(long long a, long long b) {
    long long result = 0;
    while (b) {
        if (b & 1ll) result = result * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return result;
}


long long inverse(long long x) {
    return binpow(x, mod - 2);
}

long long P(long long a, long long b) {
    if (b > a) return 0;
    if (b == 0) return 1;
    return ((fact[a] * inv[b] % mod) * inv[a - b]) % mod;
}


void init() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = inverse(fact[i]);
    }
}

int main() {
    init();
    long long n, m; cin >> n >> m;
    int ind = -1;
    long long nt = 0;
    long long mt = 0;
    long long result = 0;
    for (int i = 61; i >= 0; --i) {
        if (n & (1ll << i)) {
            long long tmp = 0;
            int cnt1 = 0;
            int cnt0 = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (m & (1ll << j)) {
                    tmp |= 1ll << j;
                    cnt1++;
                }
                else cnt0++;
            }
            long long r = nt & mt;
            long long rem = 0;
            for (int j = 61; j >= 0; --j) {
                if (r & (1ll << j)) rem++; 
            }
            for (int k = cnt0; k >= 0; --k) {
                result = (result + (0ll + k + cnt1 + rem) * P(0ll + cnt0, k) % mod) % mod;
            }
            nt |= 1ll << i;
            if (m & (1ll << i)) mt |= 1ll << i;
        }
        else {
            if (m & (1ll << i)) mt |= 1ll << i;
        }
    }
    cout << result << "\n";
    return 0;
}
