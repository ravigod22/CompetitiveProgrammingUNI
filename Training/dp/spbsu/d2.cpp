#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) prefix[i] = prefix[i - 1] + 0ll + a[i];
    auto f = [&] (int l, int r) -> long long {
        return prefix[r] - prefix[l - 1];
    };
    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = 1ll * a[i];
        }
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = n; i >= 1; --i) {
            if (i < j) dp[i][j] = f(i, j) + max(dp[i + 1][j], dp[i][j - 1]);         
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}
