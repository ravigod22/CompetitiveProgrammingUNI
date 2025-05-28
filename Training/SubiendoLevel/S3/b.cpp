#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r; cin >> r;
    for (int t = 1; t <= r; ++t) {
        int n; cin >> n;
        vector<int> a(n - 1);
        for (int& e : a) cin >> e;
        vector<i64> dp(n - 1);
        vector<int> len(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            len[i] = 1;
            dp[i] = a[i];
            if (i && dp[i - 1] >= 0) {
                dp[i] += dp[i - 1];
                len[i] += len[i - 1];
            }
        }
        i64 sum = -1e18;
        int pos = -1, l = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (dp[i] <= 0) continue;
            if (sum > dp[i]) continue;
            if (sum < dp[i]) {
                sum = dp[i];
                pos = i - len[i] + 1;
                l = len[i];
                continue;
            }
            if (l > len[i]) continue;
            if (l < len[i]) {
                pos = i - len[i] + 1;
                l = len[i];
                continue;
            }
        }
        if (l < 0) cout << "Route " << t << " has no nice parts\n";
        else cout << "The nicest part of route " << t << " is between stops " << pos + 1 << " and " << pos + l + 1 << "\n";
    }
    return 0;
}
