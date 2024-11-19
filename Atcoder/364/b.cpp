#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    int x, y; cin >> x >> y;
    x--; y--;
    string s;
    char grid[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    cin >> s;
    queue<pair<int, int>> q;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'U') q.emplace(-1, 0);
        if (s[i] == 'D') q.emplace(1, 0);
        if (s[i] == 'L') q.emplace(0, -1);
        if (s[i] == 'R') q.emplace(0, 1);
    }
    auto check = [&] (int x1, int y1) -> bool {
        if (x1 < 0 || h <= x1) return false;
        if (y1 < 0 || w <= y1) return false;
        return true;
    };
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int ii = u.first + x;
        int jj = u.second + y;
        if (check(ii, jj)) {
            if (grid[ii][jj] == '#') continue;
            x += u.first;
            y += u.second;
        }
    }
    cout << x + 1 << " " << y + 1 << "\n";
    return 0;
}
