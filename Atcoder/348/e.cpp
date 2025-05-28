#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 1e5 + 10;
vector<int> G[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> c(n);
    for (int& e : c) cin >> e;
    vector<i64> dp(n), acc(n), res(n);
    auto dfs = [&] (auto& self, int u, int p = -1) -> void {
        acc[u] = c[u];
        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            dp[u] += dp[v] + acc[v];
            acc[u] += acc[v];
        }
    };
    dfs(dfs, 0);
    auto dfs2 = [&] (auto& self, int u, int p = -1) -> void {
        for (int v : G[u]) {
            if (v == p) continue;
            res[v] = res[u] + dp[u] - dp[v] + acc[0] - 2 * acc[v];
            self(self, v, u);
        }
    };
    dfs2(dfs2, 0);
    i64 ans = 5e18;
    for (int i = 0; i < n; ++i) ans = min(ans, dp[i] + res[i]);
    cout << ans << "\n";
    return 0;
}
