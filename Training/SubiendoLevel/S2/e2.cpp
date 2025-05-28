#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

const int maxn = 22;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int n, k;
char grid[maxn][maxn];
char G[maxn][maxn];


vector<pair<int, int>> ans;
vector<vector<pair<int, int>>> states;

void solve() {
    if (ans.size() == k) {
        states.push_back(ans);
        return;
    }
    for (auto [i, j] : ans) {
        for (int d = 0; d < 4; ++d) {
            int newi = i + dx[d];
            int newj = j + dy[d];
            if (newi < 0 || newj < 0 || newi >= maxn || newj >= maxn) continue;
            if (grid[newi][newj] == '.') {
                ans.emplace_back(newi, newj);
                grid[newi][newj] = '*';
                solve();
                grid[newi][newj] = '.';
                ans.pop_back();
            }
        }
    }
}

void precomputation() {
    memset(grid, '.', sizeof(grid));
    ans.emplace_back(10, 10);
    grid[10][10] = '*';
    solve();
    grid[10][10] = '.';
    ans.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    precomputation();
    set<vector<pair<int ,int>>> res;
    for (auto& step : states) {
        sort(step.begin(), step.end());
        for (auto& [x, y] : step) x -= 10, y -= 10;
        if (res.count(step)) continue;
        res.emplace(step);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G[i][j];
        }
    }
    set<vector<pair<int ,int>>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] != '.') continue;
            for (auto step : res) {
                bool can = true;
                for (auto [x, y] : step) {
                    int newx = i + x;
                    int newy = j + y;
                    if (newx < 0 || newy < 0 || newx >= n || newy >= n) can = false;
                    if (!can) break;
                    if (G[newx][newy] != '.') can = false;
                    if (!can) break;
                }
                if (can) {
                    vector<pair<int, int>> aux;
                    for (auto [x, y] : step) aux.emplace_back(x + i, y + j);
                    sort(aux.begin(), aux.end());
                    if (ans.count(aux)) continue;
                    ans.emplace(aux);
                }
            }
        }
    }
    cout << ans.size() << "\n";
    return 0;
}

