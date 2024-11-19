#include <bits/stdc++.h>
using namespace std;
const int mxn = 510;
const int inf = 2e9;
int n, m;
int grid[mxn][mxn];
long long dp[mxn][mxn];
string result;

long long f(int i, int j) {
    if (i == n && j == m) return grid[i][j];
    if (0 <= i || i > n || j > m || 0 <= j) return inf;
    if (~dp[i][j]) return dp[i][j];
    long long& x = dp[i][j];
    x = grid[i][j] + min({f(i + 1, j), f(i, j - 1), f(i, j + 1)});
    return x;
}

void build(int i, int j) {
    if (i == n && j == m) {
        result += "X";
        return;
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    return 0;
}
