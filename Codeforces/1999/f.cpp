#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
int fact[maxn];
int invfact[maxn];

int add(int a, int b) {
    return (a + b) % mod;
}
int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int binpow(int a, int b) {
    int result = 1;
    while (b) {
        if (b & 1) result = mul(result, a);
        a = mul(a, a);
        b >>= 1;
    }
    return result;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }
    invfact[maxn - 1] = binpow(fact[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; --i) {
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

int C(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return (1LL * fact[n] * invfact[k]) % mod * invfact[n - k] % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = a[i] + prefix[i];
        int ans = 0;
        int one = prefix[n];
        for (int i = (k + 1) / 2; i <= k; ++i) {
            ans = add(ans, mul(C(one, i), C(n - one, k - i)));
        }
        cout << ans << "\n";
    }
    return 0;
}

