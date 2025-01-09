#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> dp(n + 1, n);
        reverse(a.begin(), a.end());
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 > a[i]) dp[i + 1] = dp[i - a[i]];
            dp[i + 1] = min(dp[i + 1], 1 + dp[i]);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}

