#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int dp[n][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = ((a[i - 1] == a[i] ? 0 : dp[i - 1][0]) + (b[i - 1] == a[i] ? 0 : dp[i - 1][1])) % mod;
        dp[i][1] = ((a[i - 1] == b[i] ? 0 : dp[i - 1][0]) + (b[i - 1] == b[i] ? 0 : dp[i - 1][1])) % mod;
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << "\n";
    return 0;
}
