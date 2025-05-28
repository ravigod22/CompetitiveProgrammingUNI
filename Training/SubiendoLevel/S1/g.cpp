#include <bits/stdc++.h>
using namespace std;
int n = 1, k;
char grid[1000][1000];
char base_case[10][10];

void solve(int x0, int y0, int x1, int y1) {
    int dis = x1 - x0 + 1;
    if (x1 - x0 + 1 == n) {
        for (int i = x0, a = 1; i <= x1; ++i, a++) {
            for (int j = y0, b = 1; j <= y1; ++j, b++) {
                grid[i][j] = base_case[a][b];
            }
        }
        return;
    }
    for (int i = x0, a = 1; i <= x1; i += dis / n, a++) {
        for (int j = y0, b = 1; j <= y1; j += dis / n, b++) {
            if (base_case[a][b] == '.') solve(i, j, i + dis / n - 1, j + dis / n - 1);
        }
    }
}

int main() {

#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    memset(grid, '*', sizeof(grid));
    cin >> n >> k;
    int l = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> base_case[i][j];
        }
    }
    for (int j = 0; j < k; ++j) l *= n;
    solve(1, 1, l, l);
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= l; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}
