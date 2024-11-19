#include <bits/stdc++.h>
using namespace std;

using plli = pair<long long, int>;
const int maxn = 1e5 + 10;
const long long inf = 1e18;

int n, m;
long long dis[maxn];
vector<plli> G[maxn];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, w);
        //G[v].emplace_back(u, w);
    }
    fill(dis, dis + n, inf);
    dis[0] = 0;
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    pq.emplace(dis[0], 0);
    while (pq.size()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if (dis[u] != d) continue;
        for (auto e : G[u]) {
            int to = e.first;
            long long len = 1LL * e.second;
            if (dis[u] + len < dis[to]) {
                dis[to] = dis[u] + len;
                pq.emplace(dis[to], to);
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << dis[i] << " \n"[i + 1 == n];
    return 0;
}
