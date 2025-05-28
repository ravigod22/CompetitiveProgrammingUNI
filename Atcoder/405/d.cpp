#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char step[] = {'^', 'v', '<', '>'};

int main() {
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> grid[i][j];
    vector<pair<int, int>> target;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 'E') {
                target.emplace_back(i, j);
            }
        }
    }
    bool vis[h][w];
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    for (auto [x, y] : target) {
        vis[x][y] = true;
        q.emplace(x, y);
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int newx = dx[k] + x;
            int newy = dy[k] + y;
            if (newx < 0 || newy < 0 || newx >= h || newy >= w) continue;
            if (vis[newx][newy]) continue;
            if (grid[newx][newy] == '.') {
                grid[newx][newy] = step[k];
                vis[newx][newy] = true;
                q.emplace(newx, newy);
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}
