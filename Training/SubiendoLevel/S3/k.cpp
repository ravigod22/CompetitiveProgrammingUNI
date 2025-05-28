#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp(n + 1, 1e9 + 5);
    dp[0] = -1e9;
    for (int i = 0; i < n; ++i) {
        int l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[l - 1] < a[i] && a[i] < dp[l]) {
            dp[l] = a[i];
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] < 1e9 + 5) {
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}
