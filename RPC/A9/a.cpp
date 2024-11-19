#include <bits/stdc++.h>
using namespace std;

int binpow(int a, int b, int mod) {
    int result = 1;
    while (b) {
        if (b & 1) result = 1LL * result * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return result;
}

int inverse(int x, int mod) {
    return binpow(x, mod - 2, mod);
}

void solve() {
    int n, m;
    cin >> n >> m;
    int k = 3 * n;
    int f[k + 1];
    f[0] = 1;
    for (int i = 1; i <= k; ++i) {
        f[i] = 1LL * f[i - 1] * i % m;
    }
    int tmp = binpow(f[2 * n], 2, m);
    tmp = 1LL * tmp * inverse(f[n], m);
    int total = f[3 * n];
    total = (total - tmp + m) % m;
    total = total * 2 % m;
    long long ans = ((tmp + total) % m - 1 + m) % m;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
