#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W; cin >> n >> W;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (w[i] <= j) dp[i + 1][j] = max(dp[i + 1][j], v[i] + dp[i][j - w[i]]);
        }
    }
    cout << dp[n][W] << "\n";
    return 0;
}
