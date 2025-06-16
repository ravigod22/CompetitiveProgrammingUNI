#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int W = (1 << 10) + 10;
int n, m;
vector<pair<int, int>> G[N];
bool vis[N][W];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        G[a].emplace_back(b, w);
    }
    queue<pair<int, int>> Q;
    Q.emplace(0, 0);
    vis[0][0] = 1;
    while (!Q.empty()) {
        auto [u, d] = Q.front();
        Q.pop();
        for (auto [v, w] : G[u]) {
            int nxt = w ^ d;
            if (vis[v][nxt]) continue;
            vis[v][nxt] = 1;
            Q.emplace(v, nxt);
        }
    }
    int ans = -1;
    for (int i = W - 1; i >= 0; --i) {
        if (vis[n - 1][i]) ans = i;
    }
    cout << ans << "\n";
    return 0;
}

