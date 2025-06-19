#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;
const int LOG = 20;
int n, m;
int par[N];
int sz[N];
int h[N];
int up[N][LOG];
int res[N][LOG];
vector<pair<int, int>> G[N];


void init() {
    fill(sz, sz + n, 1);
    iota(par, par + n, 0);
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

int mxedge(int a, int b) {
    if (h[a] > h[b]) swap(a, b);
    int ans = 0;
    for (int i = LOG - 1; i >= 0; --i) {
        if (h[up[b][i]] >= h[a]) {
            ans = max(ans, res[b][i]);
            b = up[b][i];
        }
    }
    assert (h[a] == h[b]);
    if (a == b) return ans;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[b][i] != up[a][i]) {
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
    cin >> n >> m;
    init();
    vector<tuple<int, int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.emplace_back(w, u, v, i);
    }
    sort(edges.begin(), edges.end());
    for (auto [w, u, v, id] : edges) {
        if (join(u, v)) {
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
    }
    dfs(0, 0);
    vector<bool> ans(m);
    for (auto [w, u, v, id] : edges) {
        int tmp = mxedge(u, v);
        ans[id] = (w <= tmp);
    }
    for (int i = 0; i < m; ++i) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
    return 0;
}

