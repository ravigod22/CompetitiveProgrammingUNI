#include <bits/stdc++.h>
using namespace std;
const int maxn = 260;
int f[maxn];
int dp[maxn][maxn];
int prefix[maxn];
int n;

int g(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r] < 1e9) return dp[l][r];
    int& x = dp[l][r];
    for (int i = l; i <= r; ++i) {
        int sum = prefix[r] - prefix[l - 1] - f[i - 1];
        if (i > l) sum += g(l, i - 1);
        if (i < r) sum += g(i + 1, r);
        x = min(x, sum);
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> f[i];
        prefix[0] = 0;
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + f[i];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 1e9;
            }
        }
        int ans = g(1, n);
        cout << ans << "\n";
    }
    return 0;
}
