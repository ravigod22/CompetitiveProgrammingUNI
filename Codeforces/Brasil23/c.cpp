#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        p--;
        G[p].push_back(i);
    }
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> ans(n, 1);
    auto dfs = [&] (auto& self, int u) -> void {
        for (int v : G[u]) {
            if (a[v] > a[u]) {
                ans[v] = 1 + ans[u];
                self(self, v);
            }
            else {
                ans[v] = ans[u];
                self(self, v);
            }
        }
    };
    dfs(dfs, 0);
    for (int i = 1; i < n; ++i) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
