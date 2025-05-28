#include <bits/stdc++.h>
using namespace std;
const char aux = 92;
char grid[(1 << 11) + 5][(1 << 11) + 5];

void solve(int x0, int y0, int l) {
    if (l == 2) {
        grid[x0][y0] = grid[x0 + 1][y0 - 1] = '/';
        grid[x0][y0 + 1] = grid[x0 + 1][y0 + l] = aux;
        grid[x0 + 1][y0] = grid[x0 + 1][y0 + 1] = '_';
        return;
    }
    solve(x0, y0, l / 2);
    solve(x0 + l / 2, y0 - l / 2, l / 2);
    solve(x0 + l / 2, y0 + l / 2, l / 2); 
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        int dis = (1 << n);
        for (int i = 1; i <= dis; ++i) {
            for (int j = 1; j <= 2 * dis; ++j) {
                grid[i][j] = ' ';
            }
        }
        solve(1, dis, dis);
        for (int i = 1; i <= dis; ++i) {
            for (int j = 1; j <= 2 * dis; ++j) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
