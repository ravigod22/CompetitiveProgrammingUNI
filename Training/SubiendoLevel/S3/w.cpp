#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= k; ++i) dp[0][i] += dp[0][i - 1];
    for (int i = 1; i <= n; ++i) {
        int dis = a[i - 1];
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = add(dp[i - 1][j], mod - (j - dis <= 0 ? 0 : dp[i - 1][j - dis - 1]));
        }
        for (int j = 1; j <= k; ++j) dp[i][j] = add(dp[i][j], dp[i][j - 1]);
    }
    int ans = add(dp[n][k], mod - (k == 0 ? 0 : dp[n][k - 1]));
    cout << ans << "\n";
    return 0;
}
