#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> G[N];
int n, a, b;
vector<int> path;
vector<int> cycle;
int dis[N], color[N], id[N];

void dfs(int u, int p = -1) {
    color[u] = 1;
    path.push_back(u);
    for (int v : G[u]) {
        if (color[v] == 2) continue;
        else if (color[v] == 1 && v != p) {
            vector<int> tmp = path;
            while (!tmp.empty() && tmp.back() != v) {
                cycle.push_back(tmp.back());
                tmp.pop_back();
            }
            cycle.push_back(v);
        }
        else if (!color[v]) dfs(v, u);
    }
    path.pop_back();
    color[u] = 2;
}
 
void dfs1(int u, int ord) {
    id[u] = ord;
    color[u] = 1;
    for (int v : G[u]) {
        if (color[v]) continue;
        dfs1(v, ord);
    }
}

void clean() {
    cycle.clear();
    for (int i = 0; i < n; ++i) {
        G[i].clear();
        dis[i] = 0;
        color[i] = 0;
    }
}

bool solve() {
    cin >> n >> a >> b;
    a--, b--;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; ++i)
        color[i] = 0;
    for (int e : cycle) {
        color[e] = 1;
    }
    for (int e : cycle) {
        dfs1(e, e);
    }
    for (int i = 0; i < n; ++i)
        color[i] = 0;
    int source = id[b];
    queue<int> q;
    q.push(source);
    color[source] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (color[v] == 1) continue;
            dis[v] = 1 + dis[u];
            color[v] = 1;
            q.push(v);
        }
    }
    bool res = (dis[b] < dis[a]);
    clean();
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}
