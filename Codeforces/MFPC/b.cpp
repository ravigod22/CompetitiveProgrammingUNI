#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 5e4 + 10;
vector<int> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> s(n);
    for (int& e : s) cin >> e;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    i64 lo = *max_element(s.begin(), s.end());
    i64 hi = 1e18;
    vector<pair<int, int>> doors;
    vector<i64> acc(n, 0);
    auto dfs = [&] (auto& self, int u, int p, i64 lim) -> void {
        acc[u] = s[u];
        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u, lim);
            acc[u] += acc[v];
        }
        vector<pair<i64, int>> childs;
        for (int v : G[u]) {
            if (v == p) continue;
            if (acc[v]) childs.emplace_back(acc[v], v);
        }
        sort(childs.rbegin(), childs.rend());
        int q = 0;
        while (q < childs.size() && acc[u] > lim) {
            doors.emplace_back(u, childs[q].second);
            acc[u] -= childs[q].first;
            q++;
        }
    };
    while (lo < hi) {
        // F F F V V V
        i64 mid = (lo + hi) / 2;
        dfs(dfs, 0, -1, mid);
        if (doors.size() <= k) hi = mid;
        else lo = mid + 1;
        doors.clear();
        acc.assign(n, 0);
    }
    dfs(dfs, 0, -1, lo);
    cout << doors.size() << "\n";
    for (auto [u, v] : doors) cout << u + 1 << " " << v + 1 << "\n";
    return 0;
}
