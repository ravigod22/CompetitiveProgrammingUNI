#include <bits/stdc++.h>
using namespace std;
const int knight_x[] = {2, 2, -2, -2, 1, -1, 1, -1};
const int knight_y[] = {1, -1, 1, -1, 2, 2, -2, -2};

bool check(int x, int y, int &n, int &m) {
    if (x < 0) return false;
    if (n <= x) return false;
    if (y < 0) return false;
    if (m <= y) return false;
    return true;
}

vector<vector<int>> BFS(int n, int m, int x, int y) {
    x--; y--;
    //-1 : White, 0 : Gray, 1 : Black
    vector<vector<int>> color(n, vector<int> (m, -1));
    vector<vector<int>> distance(n, vector<int> (m, -1));
    queue<pair<int,int>> q;
    color[x][y] = 0;
    distance[x][y] = 0;
    q.emplace(x, y);
    while (!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int new_i = u.first + knight_x[i]; 
            int new_j = u.second + knight_y[i];
            if (check(new_i, new_j, n, m)) {
                if (color[new_i][new_j] == 1) continue;
                if (color[new_i][new_j] == -1) {
                    color[new_i][new_j] = 0; 
                    distance[new_i][new_j] = distance[u.first][u.second] + 1;
                    q.emplace(new_i, new_j);
                }
            }
        }
        color[u.first][u.second] = 1;
    }
    return distance;
}

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> d = BFS(n, m, x, y);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << d[i][j] << " \n"[j + 1 == m];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
