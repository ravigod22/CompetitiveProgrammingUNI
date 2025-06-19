#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
int n;
i64 f[N], g[N], h[N];
vector<int> G[N];

void dfs(int u, int p = -1) {
    for (int v : G[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        h[u] += 1 + h[v];
    }
    f[u] = h[u];
    for (int v : G[u]) {
        if (v == p)
            continue;
        f[u] += f[v];
    }
}

void dfs1(int u, int p = -1) {
    for (int v : G[u]) {
        if (v == p) continue;
        g[v] = g[u] + f[u] - f[v] + n - 2 * h[v] - 2;
        dfs1(v, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0);
    dfs1(0);
    for (int i = 0; i < n; ++i) {
        cout << f[i] + g[i] << " \n"[i + 1 == n];
    }
    return 0;
}
