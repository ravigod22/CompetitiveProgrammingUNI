#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
