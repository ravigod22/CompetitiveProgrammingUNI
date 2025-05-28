#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, k;
int dis[N][N];
char grid[N][N];

bool is_corner(pair<int, int> pos, int op) {
    auto [x, y] = pos;
    if (op) {
        // op = 1 -> y
        if (y > 0 && grid[x][y - 1] == '.') return true;
        if (y + 1 < m && grid[x][y + 1] == '.') return true;
    }
    else {
        // op = 0 -> x
        if (x > 0 && grid[x - 1][y] == '.') return true;
        if (x + 1 < n && grid[x + 1][y] == '.') return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    memset(dis, -1, sizeof(dis));
    pair<int, int> I, E;
    cin >> I.first >> I.second >> E.first >> E.second;
    I.first -= 1, I.second -= 1;
    E.first -= 1, E.second -= 1;
    multiset<tuple<int, int, int>> Q;
    //queue<pair<int, int>> Q;
    dis[I.first][I.second] = 0;
    Q.emplace(0, I.first, I.second);
    while (!Q.empty()) {
        auto [l, x, y] = *Q.begin();
        Q.erase(Q.begin());
        for (int j = y + 1; j < m; ++j) {
            if (grid[x][j] == '#') break;
            pair<int, int> tmp = {x, j};
            if (is_corner(tmp, 1) ||  tmp == E) {
                if (~dis[x][j]) break;
                int d = j - y;
                dis[x][j] = (d + k - 1) / k + dis[x][y];
                Q.emplace(dis[x][j], x, j);
            }
        }
        for (int j = y - 1; j >= 0; --j) {
            if (grid[x][j] == '#') break;
            pair<int, int> tmp = {x, j};
            if (is_corner(tmp, 1) || tmp == E) {
                if (~dis[x][j]) break;
                int d = y - j;
                dis[x][j] = (d + k - 1) / k + dis[x][y];
                Q.emplace(dis[x][j], x, j);
            }
        }
        for (int i = x + 1; i < n; ++i) {
            if (grid[i][y] == '#') break;
            pair<int, int> tmp = {i, y};
            if (is_corner(tmp, 0) || tmp == E) {
                if (~dis[i][y]) break;
                int d = i - x;
                dis[i][y] = (d + k - 1) / k + dis[x][y];
                Q.emplace(dis[i][y], i, y);
            }
        }
        for (int i = x - 1; i >= 0; --i) {
            if (grid[i][y] == '#') break;
            pair<int, int> tmp = {i, y};
            if (is_corner(tmp, 0) || tmp == E) {
                if (~dis[i][y]) break;
                int d = x - i;
                dis[i][y] = (d + k - 1) / k + dis[x][y];
                Q.emplace(dis[i][y], i, y);
            }
        }
    }
    cout << dis[E.first][E.second] << "\n";
    return 0;
}
