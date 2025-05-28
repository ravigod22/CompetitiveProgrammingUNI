#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> coins(m);
    for (int& e : coins) cin >> e;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int e : coins) {
            if (i >= e) dp[i] = min(dp[i], 1 + dp[i - e]);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
