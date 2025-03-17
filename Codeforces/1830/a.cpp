#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9;
vector<pair<int, int>> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].emplace_back(v, i);
            G[v].emplace_back(u, i);
        }
        vector<int> dis(n, 0), res(n, 0);
        dis[0] = inf;
        auto dfs = [&] (auto& self, int u, int p) -> void {
            for (auto [v, t] : G[u]) {
                if (v == p) continue;
                dis[v] = t;
                res[v] = res[u] + (dis[v] < dis[u]);
                self(self, v, u);
            }
        };
        dfs(dfs, 0, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, res[i]);
        cout << ans << "\n";
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    return 0;
}
