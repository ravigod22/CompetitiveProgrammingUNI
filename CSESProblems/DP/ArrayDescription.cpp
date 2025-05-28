#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    vector<int> x(n);
    for (int& e : x) cin >> e;
    if (!x[0]) {
        for (int i = 1; i <= m; ++i) dp[1][i] = 1;
    }
    else dp[1][x[0]] = 1;
    for (int i = 1; i < n; ++i) {
        if (x[i]) {
            for (int j = max(1, x[i] - 1); j <= min(m, x[i] + 1); ++j) {
                dp[i + 1][x[i]] = (dp[i + 1][x[i]] + dp[i][j]) % mod;
            }
        }
        else {
            for (int j = 1; j <= m; ++j) {
                for (int k = max(1, j - 1); k <= min(m, j + 1); ++k) {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) ans = (ans + dp[n][i]) % mod;
    cout << ans << "\n";
    return 0;
}
