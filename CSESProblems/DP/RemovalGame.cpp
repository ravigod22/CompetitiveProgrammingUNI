#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 5e3 + 10;
int n;
int x[maxn];
i64 dp[maxn][maxn][2];

i64 f(int l, int r, int player) {
    if (l > r) return 0;
    if (~dp[l][r][player]) return dp[l][r][player];
    i64& res = dp[l][r][player] = 0;
    res = max(x[l] - f(l + 1, r, player ^ 1), x[r] - f(l, r - 1, player ^ 1));
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    memset(dp, -1, sizeof(dp));
    i64 sum = accumulate(x, x + n, 0LL);
    i64 ans = f(0, n - 1, 0);
    cout << (sum + ans) / 2 << "\n";
    return 0;
}
