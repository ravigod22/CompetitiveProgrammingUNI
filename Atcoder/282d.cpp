#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> color(n);
    vector<int> vis(n, -1);
    bool bipart = true;
    int one = 0, zero = 0;
    auto dfs = [&] (auto &self, int u, int c) -> void {
        vis[u] = 0;
        color[u] = c;
        if (c == 1) one++;
        else zero++;
        for (int v : G[u]) {
            if (vis[v] == 1) continue;
            else if (vis[v] == 0 && color[v] == color[u]) {
                bipart = false;
                return;
            }
            else if (vis[v] == -1) {
                self(self, v, c ^ 1);
            }
        }
        vis[u] = 1;
    };
    i64 ans = 1LL * n * (n - 1) / 2 - m;
    for (int i = 0; i < n; ++i) {
        if (vis[i] != -1) continue;
        bipart = true;
        one = 0, zero = 0;
        dfs(dfs, i, 0);
        if (bipart) {
            ans -= 1LL * one * (one - 1) / 2;
            ans -= 1LL * zero * (zero - 1) / 2;
        }
        else {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}
