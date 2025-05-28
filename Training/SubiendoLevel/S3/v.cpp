#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 3e3 + 10;
const i64 inf = 1e18;
int n;
int a[maxn];
i64 dp[maxn][maxn][2];

i64 f(int l, int r, int player) {
    if (l > r) return 0;
    if (~dp[l][r][player]) return dp[l][r][player];
    i64& x = dp[l][r][player] = -inf;
    x = max(a[l] - f(l + 1, r, player ^ 1), a[r] - f(l, r - 1, player ^ 1));
    return x;
}


int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << f(0, n - 1, 0) << "\n";
    return 0;
}
