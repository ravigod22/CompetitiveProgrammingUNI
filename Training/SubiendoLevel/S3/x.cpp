#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 4e2 + 10;
const i64 inf = 1e18;
int a[maxn];
i64 prefix[maxn];
i64 dp[maxn][maxn];

i64 f(int l, int r) {
    if (l == r) return 0;
    if (~dp[l][r]) return dp[l][r];
    i64& x = dp[l][r] = inf;
    i64 sum = prefix[r] - prefix[l - 1];
    for (int i = l; i < r; ++i) {
        x = min(x, f(l, i) + f(i + 1, r));
    }
    x += sum;
    return x;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
    cout << f(1, n) << "\n";
    return 0;
}
