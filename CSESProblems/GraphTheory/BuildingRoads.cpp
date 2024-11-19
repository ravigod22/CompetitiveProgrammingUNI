#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; 
vector<int> G[N];
int n, m;
int color[N];

void BFS(int source) {
    color[source] = 0;
    queue<int> Q;
    Q.emplace(source);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (color[v] == -1) {
                color[v] = 0;
                Q.emplace(v);
            }
        }
        color[u] = 1;
    }
}
void solve() {
    cin >> n >> m;
    memset(color, -1, sizeof(color));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> roads;
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            roads.emplace_back(i);
            BFS(i);
        }
    }
    int k = roads.size();
    cout << k - 1 << "\n";
    if (k > 1) {
        for (int i = 1; i < k; ++i) {
            cout << roads[i - 1] + 1 << " " << roads[i] + 1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
