#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main() {
    int n, m; cin >> n >> m;
    int x0, y0; cin >> x0 >> y0;
    x0--; y0--;
    int maze[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> maze[i][j];
    int dis[n][m];
    memset(dis, 0, sizeof(dis));
    dis[x0][y0] = 0;
    queue<pair<int,int>> q;
    q.emplace(x0, y0);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (maze[u.first][u.second] & (1 << i)) continue;
            else {
                int ni = u.first + dx[i];
                int nj = u.second + dy[i];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                    cout << dis[u.first][u.second] << "\n";
                    return 0;
                }
                if (dis[ni][nj] != 0) continue;
                dis[ni][nj] = 1 + dis[u.first][u.second];
                q.emplace(ni, nj);
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
