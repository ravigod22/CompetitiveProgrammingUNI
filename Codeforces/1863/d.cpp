#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        char grid[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                 cin >> grid[i][j];
            }
        }
        bool can = 1;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '.') cnt++;
            }
            if (cnt & 1) can = 0;
        }
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] != '.') cnt++;
            }
            if (cnt & 1) can = 0;
        }
        if (can) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 'L') {
                        bool change = 1;
                        for (int k = 0; k < n; ++k) {
                            if (grid[k][j] == 'L') {
                                if (change) {
                                    grid[k][j] = 'W', grid[k][j + 1] = 'B';
                                }
                                else {
                                    grid[k][j] = 'B', grid[k][j + 1] = 'W';
                                }
                                change ^= 1;
                            }
                        }
                    }
                    else if (grid[i][j] == 'U') {
                        bool change = 1;
                        for (int k = 0; k < m; ++k) {
                            if (grid[i][k] == 'U') {
                                if (change) {
                                    grid[i][k] = 'W', grid[i + 1][k] = 'B';
                                }
                                else {
                                    grid[i][k] = 'B', grid[i + 1][k] = 'W';
                                }
                                change ^= 1;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << grid[i][j];
                }
                cout << "\n";
            }
        }
        else cout << -1 << "\n";
    }
    return 0;
}
