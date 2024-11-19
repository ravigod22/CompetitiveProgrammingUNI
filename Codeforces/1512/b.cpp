#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        char grid[n][n];
        pair<int, int> tmp[2];
        int p = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == '*') {
                    tmp[p++] = {i, j};
                }
            }
        }
        if (tmp[0].first == tmp[1].first) {
            if (tmp[0].first + 1 < n) {
                grid[tmp[0].first + 1][tmp[0].second] = '*';
                grid[tmp[1].first + 1][tmp[1].second] = '*';
            } 
            else {
                grid[tmp[0].first - 1][tmp[0].second] = '*';
                grid[tmp[1].first - 1][tmp[1].second] = '*';
            }
        }
        else if (tmp[0].second == tmp[1].second) {
            if (tmp[0].second + 1 < n) {
                grid[tmp[0].first][tmp[0].second + 1] = '*';
                grid[tmp[1].first][tmp[1].second + 1] = '*';
            }
            else {
                grid[tmp[0].first][tmp[0].second - 1] = '*';
                grid[tmp[1].first][tmp[1].second - 1] = '*';
            }
        }
        else {
            grid[tmp[0].first][tmp[1].second] = '*';
            grid[tmp[1].first][tmp[0].second] = '*';
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}

