#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

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
    int n; cin >> n;
    UnionFind uf(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        uf.merge(p[i], i);
    }
    int ans = 0;
    vector<int> d(n);
    for (int& e : d) cin >> e, e--;
    set<int> ids;
    for (int i = 0; i < n; ++i) {
        int e = p[d[i]];
        int idx = uf.find(e);
        if (!ids.count(idx)) ans += uf.count(e);
        ids.insert(idx);
        cout << ans << " \n"[i + 1 == n];
    }
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


