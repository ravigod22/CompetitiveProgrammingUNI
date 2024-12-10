#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x, y; cin >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int dp[x + 1][y + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= 0; --j) {
            for (int k = y; k >= 0; --k) {
                int maxj = min(j + a[i], x);
                int maxk = min(k + b[i], y);
                dp[maxj][maxk] = min(dp[maxj][maxk], 1 + dp[j][k]); 
            }
        }
    }
    cout << (dp[x][y] >= 1e9 ? -1 : dp[x][y]) << "\n";
    return 0;
}
