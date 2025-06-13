#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};


void solve() {
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    int dis[n][m];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (!grid[i][j]) {
                dis[i][j] = 0;
                q.emplace(i, j);
            }
            else dis[i][j] = -1;
        }
    }
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int na = a + dx[k];
            int nb = b + dy[k];
            if (na < 0 || nb < 0 || na >= n || nb >= m) continue;
            if (dis[na][nb] == -1 && grid[na][nb] == 1) {
                dis[na][nb] = 1 + dis[a][b];
                q.emplace(na, nb);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
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

