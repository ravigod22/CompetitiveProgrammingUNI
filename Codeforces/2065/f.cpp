#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
vector<int> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& e : a) cin >> e, e--;
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        vector<int> ans(n, 0);
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int v : G[i]) {
                cnt[a[v]]++;
            }
            for (int v : G[i]) {
                if (cnt[a[v]] >= 2) ans[a[v]] = 1;
            }
            if (cnt[a[i]] >= 1) ans[a[i]] = 1;
            for (int v : G[i]) {
                cnt[a[v]]--;
            }
        }
        for (int i = 0; i < n; ++i) cout << ans[i];
        cout << "\n";
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    return 0;
}
