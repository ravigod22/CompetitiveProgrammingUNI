#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int n, m;
char grid[N][N];
bool vis[N][N];
int dis[N][N];

void dfs(int a, int b) {
    vis[a][b] = true;
    for (int k = 0; k < 4; ++k) {
        int ii = a + dx[k];
        int jj = b + dy[k];
        if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
        if (!vis[ii][jj] && grid[ii][jj] == '.') dfs(ii, jj);
    }
}

tuple<int, pair<int, int>, int> bfs(int a, int b) {
    vector<pair<int, int>> nodes;
    queue<pair<int, int>> q;
    vis[a][b] = true;
    dis[a][b] = 0;
    q.emplace(a, b);
    while (!q.empty()) {
        auto [u, v] = q.front();
        nodes.emplace_back(u, v);
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nu = u + dx[k];
            int nv = v + dy[k];
            if (nu < 0 || nv < 0 || nu >= n || nv >= m) continue;
            if (grid[nu][nv] == '#') continue;
            if (vis[nu][nv]) continue;
            vis[nu][nv] = true;
            dis[nu][nv] = 1 + dis[u][v];
            q.emplace(nu, nv);
        }
    }
    pair<int, int> farth = {-1, -1};
    int d = 0;
    for (int i = 0; i < nodes.size(); ++i) {
        auto [x, y] = nodes[i];
        vis[x][y] = false;
        if (d < dis[x][y]) {
            d = dis[x][y];
            farth = {x, y};
        }
    }
    return make_tuple(d, farth, nodes.size());
}

pair<int, int> compo(int a, int b) {
    auto [d, nd, sz] = bfs(a, b);
    auto [x, y] = nd;
    auto [d1, nd1, sz1] = bfs(x, y);
    dfs(a, b);
    return make_pair(sz1, d1);
}

void solve(int cas) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    int largest = 0, fartest = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j] || grid[i][j] == '#') continue;
            auto [a, b] = compo(i, j);
            cnt += 1;
            if (largest < a) {
                largest = a;
                fartest = b;
            }
        }
    }
    cout << "Case " << cas << ": " << cnt << " " << largest << " " << fartest << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vis[i][j] = false;
            dis[i][j] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; ++i) {
        solve(i);
    }
    return 0;
}
