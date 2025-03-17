#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxn = 2e5 + 5;
vector<tuple<int, int, int>> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i = 1; i < n; ++i) {
            int p, a, b; cin >> p >> a >> b;
            G[--p].emplace_back(i, a, b);
            G[i].emplace_back(p, a, b);
        }
        vector<i64> acc(n, 0);
        vector<i64> prefix;
        vector<int> ans(n);
        prefix.emplace_back(0);
        auto dfs = [&] (auto& self, int u, int p = -1) -> void {
            for (auto[v, a, b] : G[u]) {
                if (v == p) continue;
                acc[v] += acc[u] + a;
                i64 aux = prefix.back() + b;
                prefix.emplace_back(aux);
                self(self, v, u);
                prefix.pop_back();
            }
            int lo = 0;
            int hi = (int)prefix.size() - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (prefix[mid] <= acc[u]) lo = mid;
                else hi = mid - 1;
            }
            ans[u] = lo;
        };
        dfs(dfs, 0);
        for (int i = 1; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    return 0;
}
