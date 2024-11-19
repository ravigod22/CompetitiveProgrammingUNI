#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int lim = accumulate(a.begin(), a.end(), 0);
    vector<int> dp(lim + 1, 0);
    dp[0] = 1;
    for (int coin : a) {
        for (int i = lim; i >= 0; --i) {
            if (i >= coin) dp[i] |= dp[i - coin];
        }
    }
    int ans = count(dp.begin() + 1, dp.end(), 1);
    cout << ans << "\n";
    for (int i = 1; i <= lim; ++i) {
        if (dp[i]) cout << i << " \n"[i == lim];
    }
    return 0;
}
