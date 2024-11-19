#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 10;
const long long inf = 1e18;
int n, m;
vector<pair<int, int>> G[mxn];
long long dis[mxn][0];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, w);
    }
    fill(dis, dis + n, inf);
    queue<pair<int, long long>> q;
    dis[0][0] = dis[0][1] = 0LL;
    q.emplace(0, dis[0]);
    while (!q.empty()) {
        
    }
    return 0;
}
