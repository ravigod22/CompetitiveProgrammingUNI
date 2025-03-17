#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int grid[n][n];
        i64 sum = 0;
        i64 mine = 1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
                sum += grid[i][j];
                if (i + j == n - 1) mine = min(mine, 1LL * grid[i][j]);
            }
        }
        cout << sum - mine << "\n";
    }
    return 0;
}

