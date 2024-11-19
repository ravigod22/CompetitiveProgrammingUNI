#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int maxk = 1e2 + 5;
const int inf = 1e9;
int n, k;
int a[maxn];
int b[maxn];
int dp[maxn][maxk];
int f(int pos, int points) {
    if (points <= 0) return 0;
    if (pos == n) return inf;
    if (~dp[pos][points]) return dp[pos][points];
    int& x = dp[pos][points] = inf;
    x = min(x, f(pos + 1, points));
    int h = min(a[pos], b[pos]);
    int w = max(a[pos], b[pos]);
    int tmp = 0;
    int sum = 0;
    for (int i = 0; i < w - h; ++i) {
        tmp += h;
        x = min(x, tmp + f(pos + 1, points - (i + 1)));
    }
    sum = w - h;
    for (int i = 1; i < 2 * h; ++i) {
        tmp += h - (i / 2);
        if (i + 1 == 2 * h) {
            x = min(x, tmp + f(pos + 1, points - 2 * h - sum));
        }
        else {
            x = min(x, tmp + f(pos + 1, points - i - sum));
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        cout << (f(0, k) == inf ? -1 : f(0, k)) << "\n";
    }
    return 0;
}
