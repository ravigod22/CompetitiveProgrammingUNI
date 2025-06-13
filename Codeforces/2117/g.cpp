#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int N = 2e5 + 5;
vector<pair<int, int>> G[N];
int mine[N], maxe[N], parent[N];
int n, m;

void dfs(int u, int p = -1) {
    for (auto [v, w] : G[u]) {
        if (v == p) continue;
        maxe[v] = max(maxe[u], w);
        mine[v] = min(mine[u], w);
        parent[v] = u;
        dfs(v, u);
    }
}

void dfs1(int u, int p, int& L, int& R) {
    for (auto [v, w] : G[u]) {
        if (v == p) continue;
        if (w <= R) {
            L = min(L, w);
            dfs1(v, u, L, R);
        }
    }
}

void clear() {
    for (int i = 0; i < n; ++i) {
        G[i].clear();
        mine[i] = 2e9 + 7;
        maxe[i] = 0;
        parent[i] = -1;
    }
}

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind {
    vector<int> par, size;
    UnionFind(int N = 0) : par(N), size(N, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int u) {
        return (par[u] == u) ? u : (par[u] = find(par[u]));
    }
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (size[u] < size[v]) swap(u, v);
        par[v] = u;
        size[u] += size[v];
        return true;
    }
    int count(int u) {
        return size[find(u)];
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
};

void solve() {
    cin >> n >> m;
    clear();
    UnionFind uf(n);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());
    for (auto [w, u, v] : edges) 
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
    }
    dfs(0);
    int valmin = mine[n - 1], valmax = maxe[n - 1];
    dfs1(0, -1, valmin, valmax);
    cout << valmin + valmax << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



