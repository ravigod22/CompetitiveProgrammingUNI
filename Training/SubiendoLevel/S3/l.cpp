#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    const int n = s.size();
    bool is_pal[n][n];
    memset(is_pal, 0, sizeof(is_pal));
    for (int i = 0; i < n; ++i) is_pal[i][i] = true;
    for (int i = 1; i < n; ++i) is_pal[i - 1][i] = (s[i - 1] == s[i]);
    for (int d = 2; d <= n; ++d) {
        for (int i = 0; i + d < n; ++i) {
            int l = i, r = i + d;
            if (s[l] == s[r]) is_pal[l][r] = is_pal[l + 1][r - 1];
        }
    }
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int d = 0; d <= n; ++d) {
        for (int i = 0; i + d < n; ++i) {
            int l = i, r = i + d;
            dp[l][r] = is_pal[l][r];
            if (l + 1 <= r) dp[l][r] += dp[l + 1][r] + dp[l][r - 1];
            if (l + 2 <= r) dp[l][r] -= dp[l + 1][r - 1];
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
