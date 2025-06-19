#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int LOG = 20;
int n, q;
int up[N][LOG], h[N];
vector<int> G[N];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        if (v == p)
            continue;
        h[v] = 1 + h[u];
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if (h[a] > h[b]) swap(a, b);
    for (int i = LOG - 1; i >= 0; --i) {
        if (h[up[b][i]] >= h[a]) {
            b = up[b][i];
        }
    }
    assert(h[a] == h[b]);
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 0);
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int c = lca(a, b);
        cout << h[a] + h[b] - 2 * h[c] << "\n";
    }
    return 0;
}


