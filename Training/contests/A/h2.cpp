#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 10;
int n, l, m;
int dis[mxn];
int parent[mxn];
vector<int> G[mxn];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;


void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (int u : G[v]) {
        if (u != p) dfs(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }  
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int> (l + 1));
    dfs(root, root);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    preprocess(0);
    fill(dis, dis + n, -1);
    dis[0] = 0;
    parent[0] = 0;
    queue<int> Q;
    Q.emplace(0);
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (dis[v] != -1) continue;
            dis[v] = 1 + dis[u];
            parent[v] = u;
            Q.emplace(v);
        }
    }
    for (int q = 0; q < m; ++q) {
        //cout << "test -> " << q + 1 << "\n";
        int k; cin >> k;
        vector<int> node(k);
        vector<int> vis(k, 0);
        for (int& e : node) {
            cin >> e;
            e--;
        }
        int aux = -1;
        int id = -1;
        for (int i = 0; i < k; ++i) {
            if (dis[node[i]] > aux) {
                aux = dis[node[i]];
                id = node[i];
            }
        }
        assert(id != -1);
        for (int i = 0; i < k; ++i) {
            //cout << "fartest -> " << id + 1 << " , node[i] -> " << node[i] + 1 << "\n";
            //cout << "the lca -> " << lca(id, node[i]) << "\n";
            if (node[i] == id) {
                vis[i] = 1;
                continue;
            }
            if (lca(id, node[i]) == node[i]) vis[i] = 1;
            else {
                if (lca(id, node[i]) == parent[node[i]]) vis[i] = 1;
            }
        }
        int ans = count(vis.begin(), vis.end(), 1);
        cout << (ans == k ? "YES\n" : "NO\n");
    }
    return 0;
}
