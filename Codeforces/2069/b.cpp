#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> ans(n * m + 1, 0);
        vector<int> cnt(n * m + 1, 0);
        int grid[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                 cin >> grid[i][j];
                 cnt[grid[i][j]]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cur = grid[i][j];
                int aux = 0;
                for (int k = 0; k < 4; ++k) {
                    int ii = dx[k] + i;
                    int jj = dy[k] + j;
                    if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                    aux += (grid[ii][jj] == cur);
                }
                ans[grid[i][j]] = max(ans[grid[i][j]], (aux ? 2 : 1));
            }
        }
        int res = 0;
        int acc = 0;
        for (int i = 1; i <= n * m; ++i) {
            res += ans[i];
            acc = max(acc, ans[i]);
        }
        cout << res - acc << "\n";
    }
    return 0;
}

