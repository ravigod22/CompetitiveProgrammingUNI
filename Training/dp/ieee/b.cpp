#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    for (int r = 1; r <= tt; ++r) {
        int n;
        cin >> n;
        vector<int> x(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> x[i];
        vector<i64> dp(n - 1);
        vector<int> len(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            len[i] = 1;
            dp[i] = x[i];
            if (i && dp[i - 1] >= 0) {
                dp[i] += dp[i - 1];
                len[i] += len[i - 1];
            }
        }
        i64 maxe = LLONG_MIN;
        int L = -1, R = -2;
        for (int i = 0; i < n - 1; ++i) {
            if (dp[i] <= 0) continue;
            if (maxe > dp[i]) continue;
            if (maxe < dp[i]) {
                maxe = dp[i];
                L = i - len[i] + 1;
                R = i;
                continue;
            }
            if (R - L + 1 > len[i]) continue;
            if (R - L + 1 < len[i]) {
                L = i - len[i] + 1;
                R = i;
                continue;
            }
        }
        if (L < 0) cout << "Route " << r << " has no nice parts\n";
        else {
            cout << "The nicest part of route " << r << " is between stops " << L + 1 << " and " << R + 2 << "\n";
        }
    }
    return 0;
}
