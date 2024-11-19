#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, x, y;
vector<int> G[maxn];
int parent[maxn];
bool vis[maxn];

void DFS(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (vis[v]) continue;
        parent[v] = u;
        DFS(v);
    }
}

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    parent[x] = -1;
    DFS(x);
    vector<int> result;
    while (y != -1) {
        result.emplace_back(y);
        y = parent[y];
    }
    reverse(result.begin(), result.end());
    for (int e : result) cout << e << " ";
    return 0;
}

