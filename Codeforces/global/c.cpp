#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

void solve() {
    int n; cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long dp[n + 1][2];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = min(a[i] + dp[i - 1][0], a[i] + dp[i - 1][1]);
        dp[i][1] = max(abs(a[i] + dp[i - 1][0]), abs(a[i] + dp[i - 1][1]));
    }
    long long ans = max(dp[n][1], dp[n][0]);
    long long cnt[n + 1][2];
    memset(cnt, 0, sizeof(cnt));
    cnt[0][0] = cnt[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        cnt[i][0] = ((a[i] + dp[i - 1][0] == dp[i][0] ? cnt[i - 1][0] : 0) + (a[i] + dp[i - 1][1] == dp[i][0] ? cnt[i - 1][1] : 0)) % mod;
        cnt[i][1] = ((abs(a[i] + dp[i - 1][0]) == dp[i][1] ? cnt[i - 1][0] : 0) + (abs(a[i] + dp[i - 1][1]) == dp[i][1] ? cnt[i - 1][1] : 0)) % mod;
    }
    long long cnt_total = ((ans == dp[n][1] ? cnt[n][1] : 0) + (ans == dp[n][0] ? cnt[n][0] : 0)) % mod;
    cout << cnt_total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


