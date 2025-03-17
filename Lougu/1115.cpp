#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int dp[n];
    dp[0] = a[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = a[i] + max(0, dp[i - 1]);
    }
    int ans = -2e9;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}

