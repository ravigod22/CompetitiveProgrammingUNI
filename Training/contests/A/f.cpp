#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e3 + 10;
const long long inf = 1e18;
int n, m;
vector<pair<int, long long>> G[mxn];
int s[mxn];
long long ans[mxn];
bool vis[mxn];

vector<long long> dijkstra(int source) {
    vector<long long> dis(n, inf);
    dis[source] = ans[source];
    set<pair<long long, int>> q;
    q.emplace(dis[source], source);
    while (q.size()) {
        int u = q.begin() -> second;
        q.erase(q.begin());
        for (auto v : G[u]) {
            int to = v.first;
            long long len = v.second;
            if (dis[u] + (len * 1LL * s[source]) < dis[to]) {
                q.erase({dis[to], to});
                dis[to] = dis[u] + (len * 1LL * s[source]);
                q.emplace(dis[to], to);
            }
        }
    }
    return dis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> m;
        fill(G, G + n, vector<pair<int, long long>> ());
        fill(ans, ans + n, inf);
        fill(vis, vis + n, false);
        for (int i = 0; i < m; ++i) {
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        for (int i = 0; i < n; ++i) cin >> s[i];
        //cout << "node -> " << 1 << "\n";
        ans[0] = 0;
        vector<long long> init = dijkstra(0);
        //for (int i = 0; i < n; ++i) cout << init[i] << " \n"[i + 1 == n];
        for (int i = 0; i < n; ++i) ans[i] = init[i];
        queue<int> q;
        vis[0] = true;
        q.emplace(0);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v : G[u]) {
                if (vis[v.first]) continue;
                //cout << "node -> " << v.first + 1 << "\n";
                vis[v.first] = true;
                vector<long long> tmp = dijkstra(v.first);
                //for (int i = 0; i < n; ++i) cout << tmp[i] << " \n"[i + 1 == n];
                for (int i = 0; i < n; ++i) ans[i] = min(tmp[i], ans[i]);
                q.emplace(v.first);
            }
        }
        cout << ans[n - 1] << "\n";
    }
    return 0;
}
