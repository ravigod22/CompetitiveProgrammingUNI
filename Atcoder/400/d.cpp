#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    int h, w; cin >> h >> w;
    int dis[h][w];
    char grid[h][w];
    int x0, y0, x1, y1;
    memset(dis, -1, sizeof(dis));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    cin >> x0 >> y0 >> x1 >> y1;
    x0--, y0--, x1--, y1--;
    deque<array<int, 3>> q;
    q.push_front({0, x0, y0});
    while (!q.empty()) {
        auto [d, u, v] = q.front();
        q.pop_front();
        if (dis[u][v] != -1) continue;
        dis[u][v] = d;
        for (int k = 0; k < 4; ++k) {
            for (int mul = 1; mul < 3; ++mul) {
                int newu = u + dx[k] * mul;
                int newv = v + dy[k] * mul;
                if (newu < 0 || newv < 0 || newu >= h || newv >= w) continue;
                if (mul == 1 && grid[newu][newv] == '.') q.push_front({d, newu, newv});
                else q.push_back({d + 1, newu, newv});
            }
        }
    }
    cout << dis[x1][y1] << "\n";
    return 0;
}

