#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m, cycles;
int par[maxn];
int vis[maxn];
vector<int> G[maxn];

// 0 : no visited , 1 : in proccess , 2 : already visited

void DFS(int u, int parent) {
    vis[u] = 1;
    par[u] = parent;
    for (int v : G[u]) {
        if (vis[v] == 1 && v != parent) {
            cycles++;
        }
        else if (vis[v] == 0) {
            DFS(v, u); 
        }
    }
    vis[u] = 2;
}

void DFS_init() {
    cycles = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i] > 0) continue;
        DFS(i, -1);
    }
    cout << cycles << "\n";
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
    DFS_init();
    return 0;
}

