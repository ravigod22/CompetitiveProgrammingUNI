#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int r, c; cin >> r >> c;
        r--; c--;
        int grid[2][2];
        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) cin >> grid[i][j];
        cout << grid[r][c];
    }
    return 0;
}
