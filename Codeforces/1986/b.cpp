#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        int matrix[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> matrix[i][j]; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool could = true;
                int ans = 0;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (matrix[ni][nj] >= matrix[i][j]) could = false;
                    ans = max(ans, matrix[ni][nj]);
                }
                if (!could) continue;
                matrix[i][j] = ans;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " \n"[j + 1 == m];
            }
        }
    }
    return 0;
}

