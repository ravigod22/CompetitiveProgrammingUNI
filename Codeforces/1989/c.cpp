#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        int dp[n + 1][2][2];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = dp[0][1] = 0;
        for (int i = 0; i < n; ++i) {
            dp[i + 1][0] = max(dp[i][1], dp[i][0]);
            dp[i + 1][1] = max(dp[i][0] + b[i], dp[i][1]);
        }
        cout << min(dp[n][1], dp[n][0]) <<  "\n";
    }
    return 0;
}

