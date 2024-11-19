#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
char grid[maxn][maxn];
int color[maxn][maxn];
bool nopath[maxn][maxn];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '#') {
                    nopath[i][j] = true;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                        nopath[ni][nj] = true;
                    }
                }
            }
        }
        int cl = 1;
        int ans = 1;
        bool vis[n][m];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (nopath[i][j]) continue;
                if (vis[i][j]) continue;
                queue<pair<int,int>> q;
                set<pair<int,int>> s;
                vis[i][j] = true;
                color[i][j] = cl;
                s.emplace(i, j);
                q.emplace(i, j);
                while(!q.empty()) {
                    auto u = q.front();
                    q.pop();
                    if (nopath[u.first][u.second]) {
                        s.emplace(u.first, u.second);
                        continue;
                    }
                    vis[u.first][u.second] = true;
                    color[u.first][u.second] = cl;
                    for (int k = 0; k < 4; ++k) {
                        int ni = u.first + dx[k];
                        int nj = u.second + dy[k];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                        if (!vis[ni][nj] && grid[ni][nj] == '.' && !s.count(make_pair(ni, nj))){
                            s.emplace(ni, nj);
                            q.emplace(ni, nj);
                        }
                    }
                }
                int sum = s.size();
                ans = max(sum, ans);
                cl++;
                s.clear();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

