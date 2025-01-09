#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, q;
int x[maxn];
vector<int> G[maxn];
vector<int> largest[maxn];
int ind[maxn];

void dfs(int u, int p = -1) {
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    vector<int> tmp;
    bool current = true;
    while ((int)tmp.size() < 20) {
        int value = -1;
        int pos = -1;
        for (int v : G[u]) {
            if (v == p) continue;
            if (ind[v] == largest[v].size()) continue;
            int it = ind[v];
            if (value < largest[v][it]) {
                value = largest[v][it];
                pos = v;
            }
        }
        if (current) {
            if (value < x[u]) {
                value = x[u];
                pos = u;
                current = false;
            }
        }
        if (value == -1) break;
        tmp.emplace_back(value);
        if (pos != u) ind[pos]++;
    }
    largest[u] = tmp;
    tmp.clear();
}


int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(0);
    for (int i = 0; i < q; ++i) {
        int v, k; cin >> v >> k;
        v--; k--;
        cout << largest[v][k] << "\n";
    }
    return 0;
}
