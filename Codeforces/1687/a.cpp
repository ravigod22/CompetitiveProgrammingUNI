#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<i64> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
        if (k < n) {
            i64 ans = 1LL * k * (k - 1) / 2;
            i64 tmp = 0;
            for (int i = k; i <= n; ++i) {
                tmp = max(tmp, prefix[i] - prefix[i - k]);
            }
            cout << ans + tmp << "\n";
        }
        else {
            i64 ans = 1LL * k * n - (1LL * n * (n + 1)) / 2;
            cout << ans + prefix[n] << "\n";
        }
    }
    return 0;
}
