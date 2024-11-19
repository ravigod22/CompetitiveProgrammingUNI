#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> id;

const int dx[] = {-1, -1, 0, 0, 1, 1};
const int dy[] = {-1, 0, -1, 1, 0, 1};

int main() {
    int n; cin >> n;
    vector<int> G[n];
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        p.emplace_back(x, y);
        id[{x, y}] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 6; ++k) {
            int ii = dx[k] + p[i].first;
            int jj = dy[k] + p[i].second;
            if (id.count({ii, jj})) {
                G[i].emplace_back(id[{ii, jj}]);
            }
        }
    }
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (auto [x, y] : p) {
        if (vis[id[{x, y}]]) continue;
        queue<int> q;
        vis[id[{x, y}]] = true;
        q.emplace(id[{x, y}]);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (vis[v]) continue;
                q.emplace(v);
                vis[v] = true;
            }
        }
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
