#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


void solve() {
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*' || grid[i][j] == '.') {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                    cnt += (grid[ni][nj] == '#');
                    ans = max(ans, cnt);
                }
            }
        }
    }
    cout << ans << "\n";
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



