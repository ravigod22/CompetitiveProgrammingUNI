#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e3 + 5;
const int dir_x[] = {1, 0, -1, 0};
const int dir_y[] = {0, 1, 0, -1};

vector<vector<char>> G(mxn, vector<char>(mxn));
vector<vector<int>> dis(mxn, vector<int>(mxn, -1));
vector<vector<pair<int,int>>> parent(mxn, vector<pair<int,int>>(mxn, {-1, -1}));
vector<vector<int>> color(mxn, vector<int>(mxn, -1));

char back(pair<int,int> &pos_ini, pair<int,int> &pos_end) {
    if (pos_ini.first == pos_end.first) {
        return pos_ini.second > pos_end.second ? 'L' : 'R';
    }
    else {
        return pos_ini.first > pos_end.first ? 'U' : 'D';
    }
}

bool check(int &x, int &y, int &n, int &m) {
    if (x < 0) return false;
    if (n <= x) return false;
    if (y < 0) return false;
    if (m <= y) return false;
    return true;
}
void BFS(int &Ax, int &Ay, int &n, int &m) {
    //inti;
    // -1 : white, 0 : gray, 1 : black
    color[Ax][Ay] = 0;
    dis[Ax][Ay] = 0;
    parent[Ax][Ay] = {-1, -1};
    queue<pair<int,int>> q;
    q.emplace(Ax, Ay);
    while (!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int new_i = u.first + dir_x[i];
            int new_j = u.second + dir_y[i];
            if (check(new_i, new_j, n, m)) {
                if (G[new_i][new_j] == '#') continue;
                if (color[new_i][new_j] == -1) {
                    color[new_i][new_j] = 0;
                    dis[new_i][new_j] = dis[u.first][u.second] + 1;
                    parent[new_i][new_j] = {u.first, u.second};
                    q.emplace(new_i, new_j);
                }
            }
        }
        color[u.first][u.second] = 1;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int x_A = 0, y_A = 0, x_B = 0, y_B = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> G[i][j];
            if (G[i][j] == 'A') {
                x_A = i;
                y_A = j;
            }
            if (G[i][j] == 'B') {
                x_B = i;
                y_B = j;
            }
        }
    }
    BFS(x_A, y_A, n, m);
    if (dis[x_B][y_B] == -1) {
        cout << "NO\n";
        return;
    }
    int x = x_B;
    int y = y_B;
    string path;
    while (x != x_A || y != y_A) {
        pair<int,int> tmp = parent[x][y];
        pair<int,int> whe = {x, y};
        path += back(tmp, whe);
        x = tmp.first;
        y = tmp.second;
    }
    reverse(path.begin(), path.end());
    cout << "YES\n";
    cout << dis[x_B][y_B] << "\n";
    cout << path << "\n";
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

