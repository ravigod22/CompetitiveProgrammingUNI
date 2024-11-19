#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        edges.emplace_back(w, u, v);
    }
    vector<int> compo[n];
    vector<int> color(n);
    iota(color.begin(), color.end(), 0);
    for (int i = 0; i < n; ++i) compo[i].emplace_back(i);
    sort(edges.begin(), edges.end());
    long long cost = 0;
    int cnt = 0;
    for (auto e : edges) {
        int u, v, w;
        tie(w, u, v) = e;
        auto join = [&] (int x, int y) -> void {
            x = color[x];
            y = color[y];
            if (compo[x].size() < compo[y].size()) {
                for (int e : compo[x]) {
                    color[e] = y;
                    compo[y].emplace_back(e);
                }
                compo[x].clear();
            }
            else {
                for (int e : compo[y]) {
                    color[e] = x;
                    compo[x].emplace_back(e);
                }
                compo[y].clear();
            }
        };
        if (color[u] != color[v]) {
            cnt++;
            cost += 0LL + w;
            join(u, v);
        }
        if (cnt == n - 1) break;
    }
    bool can = true;
    for (int i = 1; i < n; ++i) {
        if (color[i] != color[i - 1]) can = false;
    }
    if (can) cout << cost << "\n";
    else cout << "IMPOSSIBLE\n";
    return 0;
}
