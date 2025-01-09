#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    char grid[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    string t; cin >> t;
    set<pair<int, int>> s;
    if (grid[x][y] == '#') s.emplace(x, y);
    for (char op : t) {
        int nx = x, ny = y;
        if (op == 'L') ny--;
        if (op == 'D') nx++;
        if (op == 'U') nx--;
        if (op == 'R') ny++;
        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (grid[nx][ny] == '#') continue;
        if (grid[nx][ny] == '@') s.emplace(nx, ny);
        x = nx, y = ny;
    }
    x++, y++;
    cout << x << " " << y << " " << (int)s.size() << "\n"; 
    return 0;
}

