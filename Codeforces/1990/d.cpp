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
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = (a[0] ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            dp[i + 1] = min((min(a[i], a[i - 1]) + 1) / 2 + dp[i - 1], 1 + dp[i]);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
