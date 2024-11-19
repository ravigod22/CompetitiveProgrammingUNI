#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 10;
const int inf = 2e9;
int n, m;
vector<tuple<int, int, int>> G[mxn];
bool vis[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> m;
        fill(G, G + n, vector<tuple<int, int, int>>());
        fill(vis, vis + m, false);
        for (int i = 0; i < m; ++i) {
            int u, v, w; cin >> u >> v >> w;
            --u; --v;
            G[u].emplace_back(v, w, i);
            G[v].emplace_back(u, w, i);
        }
        int ans = 0;
        for (int bit = 30; bit >= 0; --bit) {
            vector<int> on;
            vector<int> dis(n, -1);
            dis[0] = 0;
            queue<int> q;
            q.emplace(0);
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (auto e : G[u]) {
                    int v, w, id;
                    tie(v, w, id) = e;
                    if (vis[id]) continue;
                    if (w & (1 << bit)) {
                        on.emplace_back(id);
                        continue;
                    }
                    if (dis[v] != -1) continue;
                    dis[v] = 1 + dis[u];
                    q.emplace(v);
                }
            }
            int cnt = count(dis.begin(), dis.end(), -1);
            if (cnt == 0) {
                for (int e : on) vis[e] = true;
            }
            else ans |= (1 << bit);
        }
        cout << ans << "\n";
    }
    return 0;
}
