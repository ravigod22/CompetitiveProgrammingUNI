#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

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

const int maxn = 2e5 + 5;
int n, m1, m2;
vector<int> G[maxn];

void clear() {
    for (int i = 0; i < n; ++i) G[i].clear();    
}

void solve() {
    cin >> n >> m1 >> m2;
    UnionFind uf(n);
    for (int i = 0; i < m1; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for (int i = 0; i < m2; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        uf.merge(u, v);
    }
    i64 dele = 0;
    vector<int> tmp = uf.par;
    vector<bool> vis(n, 0);
    vector<int> compo[n];
    auto dfs = [&] (auto& self, int u) -> void {
        vis[u] = true;
        dele += (int)G[u].size();
        for (int v : G[u]) {
            if (vis[v]) continue;
            if (uf.same(u, v)) self(self, v);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        dfs(dfs, i);
        compo[uf.find(i)].emplace_back(i);
    }
    dele /= 2;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int v : G[i]) {
            if (uf.same(i, v)) cnt[uf.find(i)]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        assert (cnt[i] % 2 == 0);
        dele -= cnt[i] / 2;
    }
    for (int i = 0; i < n; ++i) {
        if (compo[i].size() <= 0) continue;
        dele += (int)compo[i].size() - 1;
    }
    cout << dele << "\n";
    clear();
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


