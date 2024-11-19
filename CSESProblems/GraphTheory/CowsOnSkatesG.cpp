#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e3 + 5;
const int dir_x[] = {1, -1, 0, 0};
const int dir_y[] = {0, 0, -1, 1};
const pair<int,int> nul = {-1, -1};
vector<vector<char>> G(mxn, vector<char> (mxn));
vector<vector<int>> color(mxn, vector<int> (mxn, -1));
vector<vector<pair<int,int>>> parent(mxn, vector<pair<int,int>> (mxn, nul));

bool check(int x, int y, int &r, int &c) {
    if (x < 0 || r <= x) return false;
    if (y < 0 || c <= y) return false;
    return true;
} 

void BFS(int x0, int y0, int &r, int &c) {
    //-1 : white, 0 : gray, 1 : black
    color[x0][y0] = 0;
    parent[x0][y0] = nul;
    queue<pair<int,int>> Q;
    Q.emplace(x0, y0);
    while (!Q.empty()) {
        pair<int,int> u = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int new_i = u.first + dir_x[i];
            int new_j = u.second + dir_y[i];
            if (check(new_i, new_j, r, c)) {
                if (color[new_i][new_j] == 1) continue;
                if (color[new_i][new_j] == -1 && G[new_i][new_j] == '.') {
                    color[new_i][new_j] = 0;
                    parent[new_i][new_j] = {u.first, u.second};
                    Q.emplace(new_i, new_j);
                }
            } 
        }
        color[u.first][u.second] = 1;
    }
}
void solve() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> G[i][j];
        }
    }
    BFS(0, 0, r, c);
    int x_end = r - 1;
    int y_end = c - 1;
    vector<pair<int,int>> path;
    while (x_end != -1 || y_end != -1) {
        pair<int,int> tmp = parent[x_end][y_end];
        path.emplace_back(x_end, y_end);
        x_end = tmp.first;
        y_end = tmp.second;
    }
    reverse(path.begin(), path.end());
    int p = path.size();
    for (int i = 0; i < p; ++i) {
        cout << path[i].first + 1 << " " << path[i].second + 1 << "\n"; 
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
