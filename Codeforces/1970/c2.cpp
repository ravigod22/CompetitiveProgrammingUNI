#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; cin >> n >> t;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> win(n, 1);
    auto dfs = [&] (auto& self, int u, int p = -1) -> void {
        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            win[u] &= (1 ^ win[v]);
        }
    };
    while (t--) {
        int u; cin >> u;
        u--;
        dfs(dfs, u, -1);
        cout << (win[u] ? "Hermione" : "Ron") << "\n";
    }
    return 0;
}

