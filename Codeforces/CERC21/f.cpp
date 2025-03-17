#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<char> s(k);
    for (int i = 0; i < k; ++i) cin >> s[i];
    vector<vector<char>> grid(n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    auto rotate = [&] (vector<vector<char>> &grid, char op) -> void {
        if (op == 'L') {
            for (int i = 0; i < n; ++i) {
                vector<char> aux;
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] != '.') aux.emplace_back(grid[i][j]);
                }
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == '.') aux.emplace_back(grid[i][j]);
                }
                for (int j = 0; j < m; ++j) {
                    grid[i][j] = aux[j];
                }
            }
        }
        else if (op == 'R') {
            for (int i = 0; i < n; ++i) {
                vector<char> aux;
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '.') aux.emplace_back(grid[i][j]);
                }
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] != '.') aux.emplace_back(grid[i][j]);
                }
                for (int j = 0; j < m; ++j) {
                    grid[i][j] = aux[j];
                }
            }
        }
        else if (op == 'U') {
            for (int j = 0; j < m; ++j) {
                vector<char> aux;
                for (int i = 0; i < n; ++i) {
                    if (grid[i][j] != '.') aux.emplace_back(grid[i][j]);
                }
                for (int i = 0; i < n; ++i) {
                    if (grid[i][j] == '.') aux.emplace_back(grid[i][j]);
                }
                for (int i = 0; i < n; ++i) {
                    grid[i][j] = aux[i];
                }
            }
        }
        else {
            for (int j = 0; j < m; ++j) {
                vector<char> aux;
                for (int i = 0; i < n; ++i) {
                    if (grid[i][j] == '.') aux.emplace_back(grid[i][j]);
                }
                for (int i = 0; i < n; ++i) {
                    if (grid[i][j] != '.') aux.emplace_back(grid[i][j]);
                }
                for (int i = 0; i < n; ++i) {
                    grid[i][j] = aux[i];
                }
            }
        }
    };
    for (int i = 0; i < k; ++i) {
        rotate(grid, s[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}
