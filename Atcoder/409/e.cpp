#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 1e5 + 10;
vector<pair<int, int>> G[maxn];
int x[maxn], cnt[maxn];
i64 acc[maxn], f[maxn];
int n;


void dfs(int u, int p = -1) {
    cnt[u] = x[u];
    for (auto [v, w] : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        acc[u] += 1LL * abs(cnt[v]) * w + acc[v];
        cnt[u] += cnt[v];
    }
}

void dfs1(int u, int p = -1) {
    for (auto [v, w] : G[u]) {
        if (v == p) continue;
        f[v] = f[u] + (acc[u] - acc[v]);
        dfs1(v, u);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    dfs(0);
    i64 ans = 3e18;
    dfs1(0);
    for (int i = 0; i < n; ++i) {
        ans = min(ans, f[i] + acc[i]);
    }
    cout << ans << "\n";
    return 0;
}
