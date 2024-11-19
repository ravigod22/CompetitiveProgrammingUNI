#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long inf = LLONG_MAX;

int n, m;
vector<pair<int, long long>> G[maxn];
long long dis[maxn];
bool vis[maxn];


void dfs(int u, int p = -1) {
    vis[u] = true;
    for (auto [v, w] : G[u]) {
        if (v == p) continue;
        if (vis[v]) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, 0LL + w);
        G[v].emplace_back(u, 0LL - w);
    }
    fill(vis, vis + n, false);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << dis[i] << " \n"[i + 1 == n];
    }
    return 0;
}
