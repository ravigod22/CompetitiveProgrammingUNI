#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string a, b; cin >> a >> b;
        int n = a.size();
        int m = b.size();
        int dp[n + 1][m + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i] == b[j]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + 1);
            }
        }
        for (int i = 0; i < m; ++i) {
            dp[n][i + 1] = min(dp[n][i + 1], dp[n][i] + 1);
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}

