#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    int grid[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j)
            cin >> grid[i][j];
    vector<int> ans(2 * n + 1, 0);
    vector<int> exist(2 * n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans[i + j] = grid[i][j];
            exist[grid[i][j]] = true;
        }
    }
    int last = -1;
    for (int i = 1; i <= 2 * n; ++i) {
        if (exist[i]) continue;
        last = i;
    }
    ans[1] = last;
    for (int i = 1; i <= 2 * n; ++i) cout << ans[i] << " \n"[i == 2 * n];
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


