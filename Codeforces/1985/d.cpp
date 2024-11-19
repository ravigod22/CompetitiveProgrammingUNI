#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        char grid[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> grid[i][j];
        vector<pair<int,int>> pos_col;
        vector<pair<int,int>> pos_row;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '#') sum++;
            }
            if (sum > 0) pos_row.emplace_back(i, sum);
        }
        for (int i = 0; i < m; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[j][i] == '#') sum++;
            }
            if (sum > 0) pos_col.emplace_back(i, sum);
        }
        int p = pos_col.size();
        int q = pos_row.size();
        int x = pos_col[p / 2].first;
        int y = pos_row[q / 2].first;
        cout << y + 1 << " " << x + 1 << "\n";
    }
    return 0;
}

