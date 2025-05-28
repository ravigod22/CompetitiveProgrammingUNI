#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int h, w; cin >> h >> w;
    char grid[h + 1][w + 1];
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cin >> grid[i][j];
    int dp[h + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (grid[i][j] == '#') continue;
            if (i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }  
    }
    cout << dp[h][w] << "\n";
    return 0;
}
