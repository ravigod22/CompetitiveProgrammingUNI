#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<i64, int>;
const int maxn = 1e5 + 10;
const i64 inf = 1e18;
vector<tuple<int, int, int>> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        int t[3];
        fill(G, G + n, vector<tuple<int, int, int>>());
        for (int i = 0; i < 3; ++i) cin >> t[i];
        for (int i = 0; i < m; ++i) {
            int u, v, w1, w2; cin >> u >> v >> w1 >> w2;
            u--; --v;
            G[u].emplace_back(v, w1, w2);
            G[v].emplace_back(u, w1, w2);
        }
        vector<i64> dis(n, inf);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dis[n - 1] = t[0];
        pq.emplace(dis[n - 1], n - 1);
        while (pq.size()) {
            auto aux = pq.top();
            i64 d = aux.first, u = aux.second;
            pq.pop();
            if (dis[u] != d) continue;
            for (auto v : G[u]) {
                int to;
                i64 bus, walk;
                tie(to, bus, walk) = v;
                if (t[2] <= d - bus || d <= t[1]) {
                    // use the bus
                }
            }
        }
    }
    return 0;
}
