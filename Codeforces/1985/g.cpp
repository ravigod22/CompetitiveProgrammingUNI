#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        char grid[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> grid[i][j];
        int color[n][m];
        map<int,int> cnt;
        memset(color, 0, sizeof(color));
        int cl = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (color[i][j] != 0 || grid[i][j] != '#') continue;
                int tmp = 1;
                color[i][j] = cl;
                queue<pair<int,int>> q;
                q.emplace(i, j);
                while(!q.empty()) {
                    auto u = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int ii = u.first + dx[k];
                        int jj = u.second + dy[k];
                        if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                        if (color[ii][jj]) continue;
                        if (grid[ii][jj] != '#') continue;
                        color[ii][jj] = cl;
                        q.emplace(ii, jj);
                        tmp++;
                    }
                }
                cnt[cl] = tmp;
                cl++;
            }
        }
        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << color[i][j] << " ";
            }
            cout << "\n";
        }
        for (auto e : cnt) {
            cout << "color ->" << e.first << " , cnt" << e.second << "\n"; 
        }
        */
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            set<int> s;
            int tmp = 0;
            int cnt0 = 0;
            if (i) {
                for (int j = 0; j < m; ++j) {
                    if (color[i - 1][j]) s.emplace(color[i - 1][j]); 
                }
            }
            if (i + 1 < n) {
                for (int j = 0; j < m; ++j) {
                    if (color[i + 1][j]) s.emplace(color[i + 1][j]);
                }
            }
            for (int j = 0; j < m; ++j) {
                if (color[i][j] == 0) cnt0++;
                else s.emplace(color[i][j]);
            }
            for(int e : s) {
                tmp += cnt[e];
            }
            tmp += cnt0;
            ans = max(tmp, ans);
            s.clear();
        }
        for (int i = 0; i < m; ++i) {
            set<int> s;
            int tmp = 0;
            int cnt0 = 0;
            if (i) {
                for (int j = 0; j < n; ++j) {
                    if (color[j][i - 1]) s.emplace(color[j][i - 1]);
                }
            }
            if (i + 1 < m) {
                for (int j = 0; j < n; ++j) {
                    if (color[j][i + 1]) s.emplace(color[j][i + 1]);
                }
            }
            for (int j = 0; j < n; ++j) {
                if (color[j][i] == 0) cnt0++;
                else s.emplace(color[j][i]);
            }
            for (int e : s) {
                tmp += cnt[e];
            }
            tmp += cnt0;
            ans = max(tmp, ans);
            s.clear();
        }
        cout << ans << "\n";
    }
    return 0;
}
