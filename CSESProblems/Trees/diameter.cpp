#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int dis[maxn];
vector<int> G[maxn];
int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int init = -1;
    for (int i = 0; i < n; ++i) {
        if (G[i].size() == 1) {
            init = i;
            break;
        }
    }
    fill(dis, dis + n, -1);
    dis[init] = 0;
    queue<int> q;
    q.emplace(init);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dis[v] != -1) continue;
            dis[v] = 1 + dis[u];
            q.emplace(v);
        }
    }
    int maxdis = 0;
    int aux = -1;
    for (int i = 0; i < n; ++i) {
        if (maxdis < dis[i]) {
            maxdis = dis[i];
            aux = i;
        }
    }
    fill(dis, dis + n, -1);
    dis[aux] = 0;
    q.emplace(aux);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dis[v] != -1) continue;
            dis[v] = 1 + dis[u];
            q.emplace(v);
        }
    }
    int another = *max_element(dis, dis + n);
    cout << max(max(maxdis, another), 0) << "\n";  
    return 0;
}
