#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n, m, b, c, d;
const int maxn = 5e3 + 10;
vector<pair<int, int>> G[maxn];
vector<i64> dis[maxn];
vector<int> parent[maxn];

void dijkstra(int source) {
    vector<i64> l(n, 1e16);
    vector<int> p(n, -1);
    l[source] = 0;
    set<pair<i64, int>> q;
    q.emplace(l[source], source);
    while (q.size()) {
        int u = q.begin() -> second;
        q.erase(q.begin());
        for (auto e : G[u]) {
            i64 len = e.second;
            int to = e.first;
            if (l[u] + len < l[to]) {
                q.erase({l[to], to});
                l[to] = l[u] + len;
                p[to] = u;
                q.emplace(l[to], to);
            }
        }
    }
    dis[source] = l;
    parent[source] = p;
}

int main() {
    while (true) {
        cin >> n >> b >> c >> d >> m;
        if (n == -1) break;
        // bar : b , c : charly , d : nito
        b--; c--; d--;
        fill (G, G + n, vector<pair<int, int>> ());
        fill (dis, dis + n, vector<i64> ());
        fill (parent, parent + n, vector<int> ());
        for (int i = 0; i < m; ++i) {
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        dijkstra(b);
        vector<int> p_b = parent[b];
        vector<i64> d_b = dis[b];
        vector<int> path1;
        vector<int> path2;
        int tmp = c;
        while (tmp != -1) {
            path1.emplace_back(tmp);
            tmp = p_b[tmp];
        }
        reverse(path1.begin(), path1.end());
        tmp = d;
        while (tmp != -1) {
            path2.emplace_back(tmp);
            tmp = p_b[tmp];
        }
        reverse(path2.begin(), path2.end());
        int ind = 0;
        for (int i = 0; i < path1.size(); ++i) {
            if (path1[i] == path2[ind]) ind++;
            else break;
        }
        int vtx = path1[ind];
        cout << d_b[vtx] << " " << (d_b[c] - d_b[vtx]) << " " << (d_b[d] - d_b[vtx]) << "\n";
    }
    return 0;
}
