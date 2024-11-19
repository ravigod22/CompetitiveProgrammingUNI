#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int inf = 2e9;
int n;
bool vis[maxn];
vector<int> G[maxn];
int DFS(int u) {
    vis[u] = true;
    int ans = 1;
    for (int v : G[u]) {
        if (vis[v]) continue;
        if (v == 1) continue;
        ans += DFS(v);
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int ans = 0;
    int max_e = 0;
    for (int v : G[1]) {
        int need = DFS(v);
        max_e = max(need, max_e);
        ans += need;
    }
    cout << ans - max_e + 1 << "\n";
    return 0;
}
