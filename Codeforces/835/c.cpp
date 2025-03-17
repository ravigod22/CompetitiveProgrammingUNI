#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, c; cin >> n >> q >> c;
    vector<int> x(n), y(n), s(n);
    int dp[110][110][c + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> s[i];
        for (int j = 0; j <= c; ++j) {
            dp[x[i]][y[i]][j] += (s[i] + j) % (c + 1);
        }
    }
    for (int k = 0; k <= c; ++k) {
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; j++) {
                dp[i][j][k] += dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
            }
        }
    }
    while (q--) {
        int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= (c + 1);
        int ans = dp[x2][y2][t] - dp[x2][y1 - 1][t] - dp[x1 - 1][y2][t] + dp[x1 - 1][y1 - 1][t];
        cout << ans << "\n";
    }
    return 0;
}
