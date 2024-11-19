#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m;
vector<int> G[maxn];
vector<int> cycle;
int color[maxn];
int parent[maxn];

void DFS_color(int u, int prt) {
    color[u] = 1;
    for (int v : G[u]) {
        if (!cycle.empty()) break;
        if (color[v] == 2) continue;
        if (color[v] == 1 && v != prt) {
            int tmp = u;
            cycle.emplace_back(v);
            while (tmp != v) {
                cycle.emplace_back(tmp);
                tmp = parent[tmp];
            }
            cycle.emplace_back(tmp);
            reverse(cycle.begin(), cycle.end());
        }
        if (color[v] == 0) {
            parent[v] = u;
            DFS_color(v, u);
        }
    }
    color[u] = 2;
}

void DFS() {
    for (int i = 0; i < n; ++i) {
        if (color[i]) continue;
        DFS_color(i, -1);
    }
    if (cycle.empty()) cout << "IMPOSSIBLE";
    else {
        int k = cycle.size();
        cout << k << "\n";
        for (int i = 0; i < k; ++i) cout << cycle[i] + 1 << " \n"[i + 1 == k];
    }
}


int main() {
    cin >> n >> m;
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    DFS();
    return 0;
}
