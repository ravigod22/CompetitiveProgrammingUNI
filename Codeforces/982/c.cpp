#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n;
vector<int> G[maxn];
int compo[maxn];
int ans;

void dfs(int u, int p = -1) {
    compo[u] = 1;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        compo[u] += compo[v];
        ans += (compo[v] % 2 == 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    if (n & 1) {
        cout << -1 << "\n";
        return 0;
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}
