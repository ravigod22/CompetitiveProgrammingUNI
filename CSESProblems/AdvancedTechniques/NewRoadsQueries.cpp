#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int LOG = 20;
int n, m, q;
int par[N], sz[N], up[N][LOG], res[N][LOG], h[N];
vector<pair<int, int>> G[N];

void init() {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
}

int get(int a) {
    return (par[a] == a ? a : par[a] = get(par[a]));
}

bool join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return true;
}

void dfs(int u, int p, int d = 0) {
    up[u][0] = p;
    res[u][0] = d;
    for (int i = 1; i < LOG; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        res[u][i] = max(res[u][i - 1], res[up[u][i - 1]][i - 1]);
    }
    for (auto [v, w] : G[u]) {
        if (v == p) continue;
        h[v] = 1 + h[u];
        dfs(v, u, w);
    }
}

int f(int a, int b) {
    if (get(a) != get(b)) return -1;
    if (h[a] > h[b]) swap(a, b);
    int ans = 0;
    for (int i = LOG - 1; i >= 0; --i) {
        int tmp = up[b][i];
        if (h[tmp] >= h[a]) {
            ans = max(ans, res[b][i]);
            b = up[b][i];
        }
    }
    assert (h[a] == h[b]);
    if (a == b) return ans;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            ans = max(ans, res[a][i]);
            ans = max(ans, res[b][i]);
            a = up[a][i];
            b = up[b][i];
        }
    }
    ans = max(ans, res[a][0]);
    ans = max(ans, res[b][0]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(up, -1, sizeof(up));
    cin >> n >> m >> q;
    init();
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (join(u, v)) {
            G[u].emplace_back(v, i);
            G[v].emplace_back(u, i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (~up[i][0]) continue;
        dfs(i, i);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << f(a, b) << "\n";
    }
    return 0;
}
