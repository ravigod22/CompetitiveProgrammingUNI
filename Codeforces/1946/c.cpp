#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> G[maxn];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    auto check = [&] (int x) -> bool {
        int compo = 0;
        auto dfs = [&] (auto& self, int u, int p) -> int {
            int cnt = 1;
            for (int v : G[u]) {
                if (v == p) continue;
                cnt += self(self, v, u);
            }
            if (cnt >= x) compo++, cnt = 0;
            return cnt;
        };
        int root = dfs(dfs, 0, -1);
        return (compo > k || (root >= x && compo == k));
    };
    int lo = 1;
    int hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
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
