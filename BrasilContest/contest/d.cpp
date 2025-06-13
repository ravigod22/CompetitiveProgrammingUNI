#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const int LOG = 31;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n,m;
vector<vector<int>> a;
vector<vector<int>> ban;
vector<vector<int>> vis;

void dfs(int i, int j, int b) {   
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni < 0 or nj < 0 or ni >= n or nj >= m) continue;
        if (ban[ni][nj] or ((a[ni][nj] >> b) & 1) == 1) continue;
        if (vis[ni][nj]) continue;
        dfs(ni, nj, b);
    }
}

void pv(int b) {
    cout << "b: " << b << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vis[i][j] << " \n"[j == m - 1];
        }
    }
}

int solve(int s, int t) {
    int ans = 0;
    ban.assign(n, vector<int>(m, 0));   
    for (int b = LOG - 1; b >= 0; b--) {
        vis.assign(n, vector<int>(m, 0));   
        vector<pair<int,int>> pending;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ban[i][j]) continue;
                if ((a[i][j] >> b) & 1) {
                    pending.emplace_back(i, j);
                    ban[i][j] = 1;
                }
            }
        }
        dfs(s, t, b);
        //pv(b);
        if (vis[n - 1][m - 1]) continue;
        for (auto [i, j] : pending) ban[i][j] = 0;
        ans |= 1 << b;
    }
    return ans;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    int x,y;
    cin >> x >> y;
    x--; y--;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << solve(0, 0) << " " << solve(x, y) << '\n';
    

    return 0;
}
