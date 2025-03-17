#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        vector<int> cnt(n, 0);
        auto dfs = [&] (auto& self, int u, int p) -> void {
            if (G[u].size() == 1 && u) cnt[u] = 1;
            for (int v : G[u]) {
                if (v == p) continue;
                self(self, v, u);
                cnt[u] += cnt[v];
            }
        };
        dfs(dfs, 0, -1);
        int q; cin >> q;
        while (q--) {
            int x, y; cin >> x >> y;
            x--, y--;
            cout << 1LL * cnt[x] * cnt[y] << "\n";
        }
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    return 0;
}
