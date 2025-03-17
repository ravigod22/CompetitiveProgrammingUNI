#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    int grid[n][n];
    memset(grid, 0, sizeof(grid));
    int init = 1;
    for (int i = 0; i < n; i++) {
        for (int j = (i & 1 ? 1 : 0); j < n; j += 2) {
            grid[i][j] = init++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]) continue;
            grid[i][j] = init++;
        }
    }
    if (n == 2) cout << -1 << "\n";
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j] << " \n"[j + 1 == n];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


