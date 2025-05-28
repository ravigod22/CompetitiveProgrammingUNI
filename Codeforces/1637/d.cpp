#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        int remain = 0;
        for (int& e : a) cin >> e, remain += e * e;
        for (int& e : b) cin >> e, remain += e * e;
        int tot = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
        int dp[n + 1][tot + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= tot; ++j) {
                if (dp[i][j]) {
                    dp[i + 1][j + a[i]] = dp[i + 1][j + b[i]] = 1;
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i <= tot; ++i) {
            if (dp[n][i]) {
                ans = min(ans, (n - 2) * remain + (i * i) + (tot - i) * (tot - i));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
