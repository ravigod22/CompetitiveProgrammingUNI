#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m;
vector<int> G[maxn];
bool vis[maxn];

void DFS(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (vis[v]) continue;
        DFS(v);
    }
}

void components() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        cnt++;
        DFS(i);
    }
    cout << cnt << "\n";
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    components();
    return 0;
}
