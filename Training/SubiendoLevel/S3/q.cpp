#include <bits/stdc++.h>
using namespace std;
const int maxn = 16;
int V, E;
int G[maxn][maxn];
int dp[1 << maxn][maxn];

int f(int mask, int last) {
    if (__builtin_popcount(mask) == V) {
        return G[last][0];
    }
    if (~dp[mask][last]) return dp[mask][last];
    int &x = dp[mask][last] = 1e6;
    for (int i = 0; i < V; ++i) {
        if ((mask >> i) & 1) continue;
        x = min(x, G[last][i] + f(mask | (1 << i), i));
    }
    return x;
}

int main() {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            G[i][j] = 1e6;
        }
    }
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u][v] = w;
    }
    int res = f(1, 0);
    if (res >= 1e6) res = -1;
    cout << res << "\n";
    return 0;
}
