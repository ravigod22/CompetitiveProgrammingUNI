#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x, y; cin >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    
    int dp[n + 1][x + 1][y + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            for (int k = 0; k <= y; ++k) {
                dp[i + 1][j][k] = min(dp[i][j][k], 1 + dp[i][max(j - a[i], 0)][max(k - b[i], 0)]);
            }
        }
    }
    cout << (dp[n][x][y] >= 1e9 ? -1 : dp[n][x][y]) << "\n";
    return 0;
}

