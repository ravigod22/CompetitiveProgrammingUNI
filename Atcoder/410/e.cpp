#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
const int inf = 1e9;
int n, h, w, k;
int a[N], b[N];
int dp[N][N];

void init() {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= h; ++j)
            dp[i][j] = -1;
}

int g(int pos, int remain) {
    if (remain < 0) return inf;
    if (pos == k) return (remain == 0 ? 0 : inf);
    if (~dp[pos][remain]) return dp[pos][remain];
    int &ans = dp[pos][remain] = b[pos] + g(pos + 1, remain);
    ans = min(ans, g(pos + 1, remain - a[pos]));
    return ans;
}

bool f(int monters) {
    k = monters;
    init();
    for (int j = 0; j <= h; ++j) {
        if (g(0, j) <= w) return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> h >> w;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int lo = 0;
    int hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}
