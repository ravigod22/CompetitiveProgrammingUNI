#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int dp[n + 1][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = (s[i] == 'S') + max(dp[i][1], dp[i][2]);
        dp[i + 1][1] = (s[i] == 'P') + max(dp[i][0], dp[i][2]);
        dp[i + 1][2] = (s[i] == 'R') + max(dp[i][0], dp[i][1]);
        if (s[i] == 'S') dp[i + 1][2] = -1;
        if (s[i] == 'P') dp[i + 1][0] = -1;
        if (s[i] == 'R') dp[i + 1][1] = -1;
    }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans << "\n";
    return 0;
}
