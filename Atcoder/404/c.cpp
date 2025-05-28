#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n, m, cnt;
vector<int> G[maxn];
int deg[maxn];
bool vis[maxn];


void dfs(int u) {
    vis[u] = true;
    cnt += 1;
    deg[u] = G[u].size();
    for (int v : G[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

bool check() {
    for (int i = 0; i < n; ++i)
        if (deg[i] != 2) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cnt = 0;
    dfs(0);
    if (cnt != n || !check()) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}
