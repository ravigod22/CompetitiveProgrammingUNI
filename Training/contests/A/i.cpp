#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 10;
const long long inf = 1e18;
int n, m;
vector<pair<int, long long>> G[mxn][2];

vector<long long> f(int source, int id) {
    vector<long long> dis(n, inf);
    dis[source] = 0;
    set<pair<long long, int>> s;
    s.emplace(dis[source], source);
    while (s.size()) {
        int u = s.begin() -> second;
        s.erase(s.begin());
        for (auto e : G[u][id]) {
            int to = e.first;
            long long len = e.second;
            if (dis[u] + len < dis[to]) {
                s.erase({dis[to], to});
                dis[to] = dis[u] + len;
                s.emplace(dis[to], to);
            }
        }
    }
    return dis;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        G[u][0].emplace_back(v, w);
        G[v][1].emplace_back(u, w);
    }
    vector<long long> d1 = f(0, 0);
    vector<long long> d2 = f(n - 1, 1);
    long long ans = inf;
    for (int i = 0; i < n; ++i) {
        for (auto u : G[i][0]) {
            ans = min(ans, d1[i] + (u.second / 2) + d2[u.first]);
        }
    }
    cout << ans << "\n";
    return 0;
}
