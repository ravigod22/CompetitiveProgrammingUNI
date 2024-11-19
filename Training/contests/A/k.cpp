#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int maxn = 5e5 + 10;
const int inf = 2e9;
int n, m, q;
vector<pii> G[maxn];

vector<int> dijsktra(int source) {
    vector<int> dis(n, inf);
    dis[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(dis[source], source);
    while (q.size()) {
        int u = q.top().second;
        int d_u = q.top().first;
        q.pop();
        if (d_u != dis[u]) continue;
        for (auto e : G[u]) {
            int to = e.first;
            int len = e.second;
            if (dis[u] + len < dis[to]) {
                dis[to] = dis[u] + len;
                q.emplace(dis[to], to);
            }
        }
    }
    for (int i = 0; i < n; ++i) dis[i] = (dis[i] == inf ? -1 : dis[i]);
    return dis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    for (int i = 0; i < q; ++i) {
        int u; cin >> u;
        vector<int> dis = dijsktra(u);
        int maxu = *max_element(dis.begin(), dis.end());
        int cnt = count(dis.begin(), dis.end(), maxu);
        cout << maxu << " " << cnt << "\n";
    }
    return 0;
}
