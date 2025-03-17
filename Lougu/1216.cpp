#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int pyramid[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> pyramid[i][j];
        }
    }
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = pyramid[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j) dp[i + 1][j] = max(dp[i + 1][j], pyramid[i][j] + dp[i][j - 1]);
            if (j < i) dp[i + 1][j] = max(dp[i + 1][j], pyramid[i][j] + dp[i][j]); 
        }
    }
    int ans = 0;
    for (int j = 0; j < n; ++j) ans = max(ans, dp[n][j]);
    cout << ans << "\n";
    return 0;
}
