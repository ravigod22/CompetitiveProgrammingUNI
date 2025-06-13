#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<tuple<int, int, int>> G[N];
int edge[N], vis[N];
bool ban[N];


void dfs(int u) {
    vis[u] = 1;
    for (auto [v, w, pos] : G[u]) {
        if (vis[v] || ban[pos]) continue;
        dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w; 
        cin >> u >> v >> w;
        u--, v--;
        edge[i] = w;
        G[u].emplace_back(v, w, i);
        G[v].emplace_back(u, w, i);
    }
    int ans = 0;
    for (int bit = 30; bit >= 0; --bit) {
        vector<int> tmp;
        for (int i = 0; i < m; ++i) {
            if (ban[i]) continue;
            if ((edge[i] >> bit) & 1) {
                ban[i] = 1;
                tmp.push_back(i);
            }
        }
        fill(vis, vis + n, 0);
        dfs(0);
        if (vis[n - 1]) continue;
        ans |= 1 << bit;
        for (int e : tmp) {
            ban[e] = 0;
        }
    }
    cout << ans << "\n";        
    return 0;
}
