#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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


int main() {
    int n; cin >> n;
    vector<tuple<int, int, int>> edges(n - 1);
    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
        u--, v--;
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    i64 ans = 0;
    for (auto [w, u, v] : edges) {
        ans += 1LL * w * uf.count(u) * uf.count(v);
        uf.merge(u, v);
    }
    cout << ans << "\n";
    return 0;
}
