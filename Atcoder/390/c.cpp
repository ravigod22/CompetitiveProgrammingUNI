#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    char grid[h][w];
    int aux = 0;
    int without = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') aux++;
            if (grid[i][j] == '?') without++;
        }
    }
    if (aux == 0) {
        if (without) cout << "Yes\n";
        else cout << "No\n";
        return 0;
    }
    int lx = w, ldx = -1;
    for (int j = 0; j < w; ++j) {
        int cnt = 0;
        for (int i = 0; i < h; ++i) {
            cnt += (grid[i][j] == '#');
        }
        if (cnt) {
            lx = min(lx, j);
            ldx = max(ldx, j);
        }
    }
    int ly = h, ldy = -1;
    for (int i = 0; i < h; ++i) {
        int cnt = 0;
        for (int j = 0; j < w; ++j) {
            cnt += (grid[i][j] == '#');
        }
        if (cnt) {
            ly = min(ly, i);
            ldy = max(ldy, i);
        }
    }
    for (int i = ly; i <= ldy; ++i) {
        for (int j = lx; j <= ldx; ++j) {
            if (grid[i][j] == '?') grid[i][j] = '#';
        }
    }

    for (int i = ly; i <= ldy; ++i) {
        for (int j = lx; j <= ldx; ++j) {
            if (grid[i][j] != '#') {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}


