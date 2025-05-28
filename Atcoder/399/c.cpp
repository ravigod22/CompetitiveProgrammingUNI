#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> G[maxn];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> vis(n, false);
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vis[i] = true;
        q.emplace(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (vis[v]) continue;
                q.emplace(v);
                vis[v] = true;
                cnt += 1;
            }
        }
    }
    cout << m - cnt << "\n";
    return 0;
}
