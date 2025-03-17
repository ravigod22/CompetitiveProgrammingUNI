#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 mod = 1e9 + 7;

i64 add(i64 a, i64 b) {
    return (a + b) % mod;
}

i64 mul(i64 a, i64 b) {
    return 1LL * a * b % mod;
}

i64 binpow(i64 a, i64 e) {
    i64 res = 1;
    while (e) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<i64> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = max(dp[i] + a[i], 0LL + a[i]);
        }
        i64 ans = *max_element(dp.begin(), dp.end());
        i64 remain = accumulate(a.begin(), a.end(), 0LL) - ans;
        ans %= mod;
        remain %= mod;
        if (remain < 0) remain += mod;
        i64 times = binpow(2, k);
        ans = mul(ans, times);
        ans = add(ans, remain);
        cout << ans << "\n";
    }
    return 0;
}
