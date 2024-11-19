#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

char grid[15][15];

bool check(int a, int b) {
    return clamp(a, 0, 8) == a && clamp(b, 0, 8) == b && grid[a][b] == '#';
}

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
        }
    }
    set<set<pii>> ans;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int dx = -9; dx <= 9; ++dx) {
                for (int dy = -9; dy <= 9; ++dy) {
                    if (dx == dy && dx == 0) continue;
                    int i2 = i + dx, j2 = j + dy;
                    int i3 = i + dx - dy, j3 = j + dy + dx;
                    int i4 = i - dy, j4 = j + dx;
                    if (check(i, j) && check(i2, j2) && check(i3, j3) && check(i4, j4)) {
                        set<pii> tmp;
                        tmp.emplace(i, j);
                        tmp.emplace(i2, j2);
                        tmp.emplace(i3, j3);
                        tmp.emplace(i4, j4);
                        ans.emplace(tmp);
                    }
                }
            }
        }
    }
    cout << ans.size() << "\n";
    return 0;
}
