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
        int n; cin >> n;
        map<pair<int, int>, int> pos;
        for (int i = 0; i + 1 < n; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
            if (u > v) swap(u, v);
            pos[{u, v}] = i + 1;
        }
        vector<int> ans;
        auto dfs = [&] (auto& self, int u, int p) -> int {
            int cnt = 1;
            for (int v : G[u]) {
                if (v == p) continue;
                cnt += self(self, v, u);
            }
            if (cnt == 3 && u) {
                int tmpu = u, tmpp = p;
                if (u > p) swap(tmpu, tmpp);
                ans.push_back(pos[{tmpu, tmpp}]);
                cnt = 0;
            }
            return cnt;
        };
        int root = dfs(dfs, 0, -1);
        if (root != 3) {
            cout << -1 << "\n";
        }
        else {
            int res = ans.size();
            cout << res << "\n";
            for (int e : ans) cout << e << " ";
            cout << "\n";
        }
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    return 0;
}
