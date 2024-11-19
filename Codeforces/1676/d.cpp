#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int grid[n][m];
    long long acc[n + m + 1];
    memset(acc, 0, sizeof(acc));
    map<int, long long> anti;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            acc[i + j] += 0LL + grid[i][j];
            anti[j - i] += 0LL + grid[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long tmp = acc[i + j];
            tmp += anti[j - i];
            tmp -= grid[i][j];
            ans = max(ans, tmp);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

