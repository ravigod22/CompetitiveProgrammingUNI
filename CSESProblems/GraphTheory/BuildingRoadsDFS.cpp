#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<int> G[N];
int color[N];
// 0 : white, 1 : Gray, 2 : Black
void DFS_visit(int u) {
    color[u] = 1;
    for (int v : G[u]) {
        if (color[v] == 2) continue;
        if (color[v] == 0) {
            DFS_visit(v);
        }
    }
    color[u] = 2;
}

void DFS() {
    vector<int> roads;
    for (int i = 0; i < n; i++) {
        if (color[i]) continue;
        roads.emplace_back(i);
        DFS_visit(i);
    }
    int k = roads.size();
    cout << k - 1 << "\n";
    if (k > 1) {
        for (int i = 1; i < k; ++i) {
            cout << roads[i - 1] + 1 << " " << roads[i] + 1 << "\n";
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    DFS();
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

