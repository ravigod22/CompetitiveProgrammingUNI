#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> G[maxn];

void solve() {
    int n; cin >> n;
    int st, en; cin >> st >> en;
    st--; en--;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> ans;
    auto dfs = [&] (auto& self, int u, int p = -1) -> void {
        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            ans.push_back(v);
        }
    };
    dfs(dfs, en);
    ans.push_back(en);
    for (int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i + 1 == n];
    for (int i = 0; i < n; ++i) G[i].clear();
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
