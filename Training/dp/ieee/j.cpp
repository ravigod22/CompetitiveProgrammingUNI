#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> c(m);
    for (int& e : c) cin >> e;
    int dp[n + 1];
    memset(dp, 0x3f ,sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int e : c) {
            if (i >= e) dp[i] = min(dp[i], 1 + dp[i - e]);
        }
        //cout << i << "\n" << dp[i] << " \n"[i == n];
    }
    cout << dp[n] << "\n";
    return 0;
}
