#include <bits/stdc++.h>
using namespace std;
const int dir_x[] = {0, 0, 1, - 1};
const int dir_y[] = {1, -1, 0, 0};

void BFS(int i, int j, vector<vector<char>> &G, vector<vector<int>> &color) {
    queue<pair<int,int>> q;
    color[i][j] = 0;
    q.emplace(i, j);
    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int new_i = u.first + dir_x[k];
            int new_j = u.second + dir_y[k];
            if (G[new_i][new_j] == '#') continue;
            if (color[new_i][new_j] == -1) {
                color[new_i][new_j] = 0;
                q.emplace(new_i, new_j);
            }
        }
        color[u.first][u.second] = 1;
    }
}
int BFS_init(int n, int m, vector<vector<char>> &G) {
    //-1 : white, 0 : gray, 1 : black 
    const int a = G.size();
    const int b = G[0].size();
    //init
    vector<vector<int>> color(a, vector<int> (b, -1));
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(color[i][j] == 1) continue;
            if (color[i][j] == -1 && G[i][j] == '.') {
                BFS(i, j, G, color);
                cnt++;
            }
        }
    }
    return cnt;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> G(n + 2, vector<char> (m + 2, '#'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x;
            cin >> x;
            G[i][j] = x;
        }
    }
    cout << BFS_init(n, m, G);
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
