#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> t(n);
    for (int& e : a) cin >> e;
    for (int& e : t) cin >> e;
    vector<int> prefix(n + 1, 0);
    vector<int> sum(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[i] * t[i];
        prefix[i + 1] = prefix[i] + a[i];
        cnt[i + 1] = cnt[i] + t[i];
    }
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i >= k) {
            dp[i] = max(dp[i], (sum[n] - sum[i]) + (prefix[i] - prefix[i - k]) + sum[i - k]);      
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
