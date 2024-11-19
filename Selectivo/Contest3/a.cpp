#include <bits/stdc++.h>
using namespace std;

const int maxn = 11;
int n, m;
char grid[maxn][maxn];

const string tmp = {"YOKOHAMA"};
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0 , 0};
int dp[maxn][maxn][maxn];

int f(int pos, int x, int y) {
    if (pos == 7) return 1;
    if (~dp[pos][x][y]) return dp[pos][x][y];
    int& ans = dp[pos][x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        int ii = x + dx[i];
        int jj = y + dy[i];
        if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
        if (grid[ii][jj] == tmp[pos + 1]) ans += f(pos + 1, ii, jj);
    }
    return ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'Y') res += f(0, i, j);
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
