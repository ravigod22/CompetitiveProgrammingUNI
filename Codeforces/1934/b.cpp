#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int maxn = 1e6;
    int dp[maxn], coins[] = {1, 3, 6, 10, 15};
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < maxn; ++i) {
        for (int x : coins) {
            if (i >= x) dp[i] = min(dp[i], 1 + dp[i - x]);
        }
    } 
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        if (n >= maxn) {
            int res = (n - maxn) / 15 + 10;
            n -= res * 15;
            ans += res;
        }
        cout << ans + dp[n] << "\n";
    }
    return 0;
}
