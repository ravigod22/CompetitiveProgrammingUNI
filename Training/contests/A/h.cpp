#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 10;
int n, m;
int dis[mxn];
int parent[mxn];
vector<int> G[mxn];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    fill(dis, dis + n, -1);
    dis[0] = 0;
    parent[0] = -1;
    queue<int> q;
    q.emplace(0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            q.emplace(v);
            parent[v] = u;
        }
    }
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        vector<int> node(k);
        vector<int> vis(k, 0);
        for (int& e : node) {
            cin >> e;
            e--;
        }
        int aux = -1;
        int id = -1;
        for (int j = 0; j < k; ++j) {
            if (dis[node[j]] > aux) {
                aux = dis[node[j]];
                id = node[j];
            }
        }
        assert(id != -1);
        //cout << "fartest node -> " << id << "\n";
        //for (auto e : s) cout << e << " ";
        //cout << endl;
        int tmp = id;
        set<int> path;
        while (tmp != -1) {
            path.emplace(tmp);
            tmp = parent[tmp];
        }
        for (int j = 0; j < k; ++j) {
            if (path.count(node[j])) vis[j] = 1;
            else {
                if (path.count(parent[node[j]])) vis[j] = 1;
            }
        }
        //cout << "the path\n";
        //for (auto e : path) cout << e << " ";
        //cout << endl;
        int ans = count(vis.begin(), vis.end(), 1);
        cout << (ans == k ? "YES\n" : "NO\n");
    }
    return 0;
}
