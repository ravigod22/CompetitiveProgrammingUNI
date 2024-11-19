#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
vector<vector<int>> G(mxn, vector<int>());
vector<int> dis(mxn, -1);
vector<int> parent(mxn, -1);
vector<int> color(mxn, -1);

void BFS(int source) {
    //init
    //-1 : white, 0 : gray, 1 : black;
    color[source] = 0;
    dis[source] = 0;
    parent[source] = -1;
    queue<int> Q;
    Q.emplace(source);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int& v : G[u]) {
            if (color[v] == -1) {
                color[v] = 0;
                dis[v] = dis[u] + 1;
                parent[v] = u;
                Q.emplace(v);
            }
        }
        color[u] = 1;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    BFS(0);
    int Maija = n - 1;
    if (dis[Maija] == -1) {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<int> path;
    while (Maija != -1) {
        path.emplace_back(Maija);
        Maija = parent[Maija];
    }
    reverse(path.begin(), path.end());
    int p = path.size();
    cout << p << "\n";
    for (int i = 0; i < p; ++i) {
        cout << path[i] + 1 << " \n"[i + 1 == p];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}

