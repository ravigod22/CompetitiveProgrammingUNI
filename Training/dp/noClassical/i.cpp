#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, inf);
    dp[0] = dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i], 1 + dp[i - 1]);
        if (i % 2 == 0) dp[i] = min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = min(dp[i], 1 + dp[i / 3]);
    }
    cout << dp[n] << "\n";
    return 0;
}
