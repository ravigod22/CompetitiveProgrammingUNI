#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int n;
int cnt[maxn], dp[maxn];
vector<int> G[maxn];

void dfs(int u, int p = -1) {
    cnt[u] = 1;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    vector<int> tmp;
    for (int v : G[u]) {
        if (v == p) continue;
        tmp.emplace_back(v);
    }
    if (tmp.size() == 1) {
        dp[u] = cnt[tmp.back()] - 1;
    }
    else if (tmp.size() == 2) {
        int a = tmp.front();
        int b = tmp.back();
        dp[u] = max(dp[a] + cnt[b] - 1, dp[b] + cnt[a] - 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        G[i].clear();
        cnt[i] = dp[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(0);
    cout << dp[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
