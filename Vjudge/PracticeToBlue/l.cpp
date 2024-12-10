#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct dsu {
    vector<int> par, size;
    dsu(int n = 0) : par(n), size(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        return (par[x] == x) ? x : (par[x] = find(par[x]));
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        par[y] = x;
        size[x] += size[y];
        return true;
    }
    int count(int x) {
        return size[find(x)];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int main() {
    int n; cin >> n;
    vector<tuple<int, int, int>> edge;
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edge.emplace_back(w, u, v);
    }
    sort(edge.begin(), edge.end());
    dsu uf(n);
    i64 ans = 0;
    for (auto [w, u, v] : edge) {
        ans += 1LL * w * uf.count(u) * uf.count(v);
        uf.merge(u, v);
    }
    cout << ans << "\n";
    return 0;
}
