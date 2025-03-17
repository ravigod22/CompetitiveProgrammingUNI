#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 15;
int n, m;
vector<pair<int, i64>> G[maxn];
vector<bool> vis(maxn, 0);
i64 ans;

void dfs(int u, i64 xorpath) {
    if (u + 1 == n) {
        ans = min(ans, xorpath);
        return;
    }
    for (auto [v, w] : G[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        dfs(v, xorpath ^ w);
        vis[v] = false;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        i64 w; cin >> w;
        u--, v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    ans = 4e18;
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}

