#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= x; ++i) {
            for (int value : a) {
                if (i >= value && 2 * value >= i) {
                    dp[i] += dp[i - value];
                    dp[i] %= MOD;
                }
            }
        }
        cout << dp[x] << "\n";
    }
    return 0;
}
