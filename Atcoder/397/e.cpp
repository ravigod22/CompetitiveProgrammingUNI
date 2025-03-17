#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 2e5 + 5;
int n, k;
vector<int> G[maxn];


int main() {
    cin >> n >> k;
    for (int i = 1; i < n * k; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<i64> dp(n * k + 1, 0);
    int cnt = 0;
    auto dfs = [&] (auto& self, int u, int p = -1) -> void {
        dp[u] = 1;
        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            dp[u] += dp[v];
        }
        if (dp[u] == k) dp[u] = 0, cnt++;
    };
    dfs(dfs, 0);
    cout << (dp[0] == 0 && cnt == n ? "Yes" : "No") << "\n";
    return 0;
}
