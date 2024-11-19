#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int n, m;
vector<int> G[maxn];
bool vis[maxn];

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vis[n - 1] = 1;
    dfs(n - 2);
    vis[n - 1] = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) cout << "B";
        else cout << "A";
    }
    return 0;
}
