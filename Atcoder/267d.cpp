#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    i64 dp[m + 1][n + 1];
    memset(dp, 0xc1, sizeof(dp));
    fill(dp[0], dp[0] + n + 1, 0);
    for (int j = 1; j <= m; ++j) {
        for (int i = j; i <= n; ++i) {
            dp[j][i] = max(dp[j][i - 1], 1LL * j * a[i] + dp[j - 1][i - 1]); 
        }
    }
    cout << dp[m][n] << "\n";
    return 0;
}
