#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
    int n; cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (j >= i) dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
