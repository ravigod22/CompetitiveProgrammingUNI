#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
const int inf = 1e9 + 10;
int n, W;
int v[N], w[N];
int dp[N][10010];
int f(int pos, int val) {
    if (pos == n) return (val == 0 ? 0 : inf);
    if (val < 0) return inf;
    if (~dp[pos][val]) return dp[pos][val];
    int& x = dp[pos][val] = inf;
    x = min(f(pos + 1, val), w[pos] + f(pos + 1, val - v[pos]));
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n >> W;
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];
    int ans = 0;
    for (int i = 0; i <= 10000; ++i) {
        int possible = f(0, i);
        if (possible <= W) {
            ans = max(ans, i);
        }
    }
    cout << ans << "\n";
    return 0;
}
