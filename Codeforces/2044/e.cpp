#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 binpow(i64 a, i64 e) {
    i64 res = 1;
    while (e) {
        if (e & 1) res *= a;
        a *= a;
        e /= 2;
    }
    return res;
}

void solve() {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    int nlim = 0;
    i64 tmp = 1;
    while (tmp < (i64)r2) {
        tmp *= k;
        nlim++;
    }
    i64 ans = 0;
    for (int i = 0; i <= nlim; ++i) {
        i64 kn = binpow(k, i);
        i64 newL = (1LL * l2 + kn - 1) / kn;
        i64 newR = (1LL * r2) / kn;
        i64 L = max(newL, 1LL * l1);
        i64 R = min(newR, 1LL * r1);
        ans += max(0LL, R - L + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

