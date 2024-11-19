#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    char grid[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    bool vis[n][m];
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j]) continue;
            if (grid[i][j] == '#') continue;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            vis[i][j] = true;
            while (q.size()) {
                auto u = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int ii = dx[k] + u.first;
                    int jj = dy[k] + u.second;
                    if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                    if (grid[ii][jj] == 'F' && !vis[ii][jj]) {
                        vis[ii][jj] = true;
                        q.emplace(ii, jj);
                    }
                }
            }
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
