#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        char grid[n][m];
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == '1') cnt++;
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                int tmp = 0;
                tmp += (grid[i][j] - '0');
                tmp += (grid[i - 1][j - 1] - '0');
                tmp += (grid[i][j - 1] - '0');
                tmp += (grid[i - 1][j] - '0');
                int tmp2 = cnt - tmp;
                if (tmp == 1) {
                    ans = max(ans, tmp2 + 1);
                }
                else if (tmp == 0) {
                    ans = max(ans, tmp2);
                }
                else if (tmp > 1) {
                    ans = max(ans, tmp2 + 2);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

