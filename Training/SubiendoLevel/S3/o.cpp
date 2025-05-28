#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (s[i] - '0');
        }
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int j = 0; j < i; ++j) {
                int dis = i - j;
                if (prefix[i] - prefix[j] > dis / 2) dp[i] = max(dp[i], dis + dp[j]);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
