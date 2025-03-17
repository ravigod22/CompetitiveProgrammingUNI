#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 2e5 + 5;
vector<int> G[maxn];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        vector<int> sz(n, 0);
        vector<i64> ans(n, 0);
        auto dfs1 = [&] (auto& self, int u, int p = -1) -> void {
            sz[u] = 1;
            for (int v : G[u]) {
                if (v == p) continue;
                self(self, v, u);
                sz[u] += sz[v];
                ans[0] += 1LL * (a[u] ^ a[v]) * (sz[v]);
            }
        };
        dfs1(dfs1, 0);
        auto dfs2 = [&] (auto& self, int u, int p = -1) -> void {
            for (int v : G[u]) {
                if (v == p) continue;
                ans[v] += ans[u] + 1LL * (a[u] ^ a[v]) * (n - 2 * sz[v]);
                self(self, v, u);
            }
        };
        dfs2(dfs2, 0);
        for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    return 0;
}

