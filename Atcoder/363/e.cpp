#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxg = 1e3 + 10;
const int maxy = 1e6 + 10;
const int maxa = 1e5 + 10;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int h, w, y;
vector<pair<int, int>> G[maxa];
int grid[maxg][maxg];
int years[maxy];
bool vis[maxg][maxg];

int main() {
    cin >> h >> w >> y;
    int mine = inf;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            G[grid[i][j]].emplace_back(i, j);
        }
    }
    for (int i = 1; i <= 1e5; ++i) {
        if (G[i].size() == 0) continue;
        queue<pair<int, int>> q;
        for (auto e : G[i]) {
            if (vis[e.first][e.second]) continue;
        }
    }
    return 0;
}
