#include <bits/stdc++.h>
using namespace std;

int h, w, d;
const int maxn = 1e3 + 5;
char g[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dis[maxn][maxn];

int main() {
    cin >> h >> w >> d;
    queue<pair<int, int>> q;
    
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            dis[i][j] = -1;
            cin >> g[i][j];
            if (g[i][j] == 'H') {
                dis[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
    int cnt = q.size();
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int ii = x + dx[k];
            int jj = y + dy[k];
            if (ii <= 0 || jj <= 0 || ii > h || jj > w) continue;
            if (g[ii][jj] == '#') continue;
            if (dis[ii][jj] != -1) continue;
            dis[ii][jj] = 1 + dis[x][y];
            if (dis[ii][jj] > d) continue;
            q.emplace(ii, jj);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
