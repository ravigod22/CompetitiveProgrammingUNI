#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 3e3 + 10;
const i64 inf = 1e18;
int n;
int a[maxn];
i64 dp[2][maxn][maxn];

i64 f(int jugador, int l, int r) {
    if (l > r) return 0;
    if (~dp[jugador][l][r]) return dp[jugador][l][r];
    i64 &res = dp[jugador][l][r] = -inf;
    res = max(res, 1LL * a[l] - f(jugador ^ 1, l + 1, r));
    res = max(res, 1LL * a[r] - f(jugador ^ 1, l, r - 1));
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << f(0, 0, n - 1) << "\n";
    return 0;
}
