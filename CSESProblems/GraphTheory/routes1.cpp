#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long inf = 1e18;
int n, m;
long long dis[maxn];
vector<pair<int, int>> G[maxn];


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    fill(dis, dis + n, inf);
    dis[0] = 0;
    set<pair<long long, int>> S;
    S.emplace(0, 0);
    while (!S.empty()) {
        auto u = *S.begin();
        S.erase(S.begin());
        for (auto v : G[u.second]) {
            int to = v.first;
            int len = v.second;
            if (dis[u.second] + 0ll + len < dis[to]) {
                S.erase({dis[to], to});
                dis[to] = dis[u.second] + len;
                S.emplace(dis[to], to);
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << dis[i] << " \n"[i + 1 == n];
    return 0;
}
