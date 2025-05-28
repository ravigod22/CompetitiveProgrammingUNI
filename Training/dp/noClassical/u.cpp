#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    i64 dp[n + 1][3];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = dp[i][0] + dp[i][1] + dp[i][2];
        dp[i + 1][1] = dp[i][0];
        if(i) dp[i + 1][2] = dp[i - 1][0];
    }
    i64 ans = dp[n][0] + dp[n][1] + dp[n][2];
    cout << ans << "\n";
    return 0;
}
