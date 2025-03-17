#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;
        for (int i = 0; i < n; ++i) {
            if (i + k < n) {
                G[i].emplace_back(i + k);
                G[i + k].emplace_back(i);
            }
            if (i + k + 1 < n) {
                G[i].emplace_back(i + k + 1);
                G[i + k + 1].emplace_back(i);
            }
        }        
        vector<int> neighbors;
        vector<bool> vis(n, false);
        auto dfs = [&] (auto& self, int u) -> void {
            vis[u] = true;
            neighbors.emplace_back(u);
            for (int v : G[u]) {
                if (vis[v]) continue;
                self(self, v);
            }
        };
        bool can = true;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            dfs(dfs, i);
            vector<int> cnt(26, 0);
            for (int e : neighbors) {
                cnt[s[e] - 'a']++;
                cnt[t[e] - 'a']--;
            }
            for (int e : cnt) {
                if (e != 0) can = false;
            }
            neighbors.clear();
        }
        cout << (can ? "YES" : "NO") << "\n";
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
    }
    return 0;
}
