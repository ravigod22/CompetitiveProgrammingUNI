#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> c(n);
    for (int& e : c) cin >> e;
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int coin : c) {
        for (int i = k; i >= 0; --i) {
            if (i >= coin) dp[i] |= dp[i - coin];
        }
    }
    int ans = count(dp.begin(), dp.end(), 1);
    cout << ans << "\n";
    for (int i = 0; i <= k; ++i) {
        if (dp[i]) cout << i << " \n"[i == k];
    }
    return 0;
}
