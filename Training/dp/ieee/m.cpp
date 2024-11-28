#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    const int n = s.size();
    bool palin[n][n];
    int dp[n][n];
    memset(palin, 0, sizeof(palin));
    for (int i = 0; i < n; ++i) palin[i][i] = 1;
    for (int i = 1; i < n; ++i) palin[i - 1][i] = (s[i - 1] == s[i]);
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            if (s[j] == s[j + i]) palin[j][j + i] = palin[j + 1][j + i - 1];
        }
    }
    for (int k = 0; k <= n; ++k) {
        for (int i = 0; i + k < n; ++i) {
            int j = i + k;
            dp[i][j] = palin[i][j];
            if (i + 1 <= j) dp[i][j] += dp[i + 1][j] + dp[i][j - 1];
            if (i + 2 <= j) dp[i][j] -= dp[i + 1][j - 1];
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        cout << dp[l][r] << "\n";
    }
    return 0;
}
