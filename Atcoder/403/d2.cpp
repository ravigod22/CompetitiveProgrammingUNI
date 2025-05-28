#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int cnt[maxn];
int dp[maxn][2];

int main() {
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x] += 1;
    }
    if (d == 0) {
        int ans = 0;
        for (int i = 0; i <= 1e6; ++i) {
            ans += max(0, cnt[i] - 1);
        }
        cout << ans << "\n";
        return 0;
    }
    for (int i = 0; i < d; ++i) dp[i][1] = cnt[i];
    int ans = 0;
    for (int i = 0; i < d; ++i) {
        int last = 0;
        for (int j = i + d; j <= 1e6; j += d) {
            last = max(last, j);
            dp[j][0] = dp[j - d][1];
            dp[j][1] = cnt[j] + min(dp[j - d][0], dp[j - d][1]);
        }
        ans += min(dp[last][0], dp[last][1]);
    }
    cout << ans << "\n";
    return 0;
}
