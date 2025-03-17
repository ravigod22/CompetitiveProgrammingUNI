#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    const int n = 20;
    int grid[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string s; cin >> s;
            grid[i][j] = stoi(s);
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    i64 res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 3 < n; ++j) {
            i64 ans = 1;
            for (int k = j; k < j + 4; ++k) {
                ans *= 1LL * grid[i][k];
            }
            res = max(res, ans);
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i + 3 < n; ++i) {
            i64 ans = 1;
            for (int k = i; k < i + 4; ++k) {
                ans *= 1LL * grid[k][j];
            }
            res = max(res, ans);
        }
    }
    vector<int> dia[2 * n + 1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dia[i + j].push_back(grid[i][j]);
        }
    }
    for (int i = 0; i <= 2 * n; ++i) {
        const int l = (int)dia[i].size();
        for (int j = 0; j + 3 < l; ++j) {
            i64 ans = 1;
            for (int k = j; k < j + 4; ++k) {
                ans *= 1LL * dia[i][k];
            }
            res = max(res, ans);
        }
    }
    fill(dia, dia + 2 * n + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dia[n + i - j].push_back(grid[i][j]);
        }
    }
    for (int i = 0; i <= 2 * n; ++i) {
        const int l = (int)dia[i].size();
        for (int j = 0; j + 3 < l; ++j) {
            i64 ans = 1;
            for (int k = j; k < j + 4; ++k) {
                ans *= 1LL * dia[i][k];
            }
            res = max(res, ans);
        }
    }
    cout << res << "\n";
    return 0;
}
