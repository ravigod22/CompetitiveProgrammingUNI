#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 1e3 + 5;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int n, m;
char grid[maxn][maxn];
bool vis[maxn][maxn];
int color[maxn][maxn];


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            vis[i][j] = 0;
            color[i][j] = -1;
            cin >> grid[i][j];
        }
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '?') continue;
            if (vis[i][j]) continue;
            int ni = i, nj = j;
            if (grid[i][j] == 'L') nj--;
            if (grid[i][j] == 'R') nj++;
            if (grid[i][j] == 'U') ni--;
            if (grid[i][j] == 'D') ni++;
            if (ni <= 0 || ni > n || nj <= 0 || nj > m) {
                vis[ni][nj] = true;
                color[ni][nj] = 1;
                q.emplace(ni, nj);
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int ii = dx[k] + x;
                        int jj = dy[k] + y;
                        if (ii <= 0 || ii > n || jj <= 0 || jj > m) continue;
                        if (vis[ii][jj] || grid[ii][jj] == '?') continue;
                        int dirx = ii, diry = jj;
                        if (grid[ii][jj] == 'L') diry--;
                        if (grid[ii][jj] == 'R') diry++;
                        if (grid[ii][jj] == 'U') dirx--;
                        if (grid[ii][jj] == 'D') dirx++;
                        if (dirx == x && diry == y) {
                            vis[ii][jj] = true;
                            color[ii][jj] = 1;
                            q.emplace(ii, jj);
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vis[i][j]) continue;
            bool can = false;
            for (int k = 0; k < 4; ++k) {
                int ii = dx[k] + i;
                int jj = dy[k] + j;
                if (ii <= 0 || ii > n || jj <= 0 || jj > m) continue;
                if (color[ii][jj] == 1) continue;
                can = true;
            }
            vis[i][j] = true;
            if (can) color[i][j] = 0;
            else color[i][j] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += (color[i][j] == 0);
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

