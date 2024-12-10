#include <bits/stdc++.h>
using namespace std;

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


int main() {
    const int N = 100;
    // Inicialization
    UnionFind uf(N);
    
    // Merge
    uf.merge(1, 2);
    uf.merge(3, 5);
    uf.merge(2, 3);
    
    // component's size of node 2
    cout << uf.count(2) << "\n";

    // same component?
    cout << (uf.same(1, 5) ? "YES" : "NO") << "\n";

    // find a leader of component
    cout << uf.find(5) << "\n";

    return 0;
}
