#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    i64 dp[n][n][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) dp[i][i][0] = dp[i][i][1] = 1LL * a[i];
    for (int dis = 1; dis < n; ++dis) {
        for (int j = 0; j + dis < n; ++j) {
            int L = j;
            int R = j + dis;
            for (int k : {0, 1}) {
                dp[L][R][k] = max(1LL * a[L] - dp[L + 1][R][k ^ 1], 1LL * a[R] - dp[L][R - 1][k ^ 1]);
            }
        }  
    }
    cout << dp[0][n - 1][0] << "\n";
    return 0;
}
