#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int dp[N][2];
vector<int> G[N];

void dfs(int u, int p = -1) {
    int sum = 0;
    for (int v : G[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        sum += max(dp[v][1], dp[v][0]);
    }
    dp[u][0] = sum;
    for (int v : G[u]) {
        if (v == p) continue;
        dp[u][1] = max(dp[u][1], 1 + dp[v][0] + sum - max(dp[v][1], dp[v][0]));
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0);
    cout << max(dp[0][0], dp[0][1]) << "\n";
    return 0;
}
