#include <bits/stdc++.h>
using namespace std;
const int mxn = 5e5 + 10;
vector<int> G[mxn];
set<int> nodes;

vector<int> solve(int k) {
    vector<int> result;
    result.emplace_back(k);
    nodes.erase(k);
    queue<int> Q;
    Q.emplace(k);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        set<int> tmp(nodes);
        for (int v : G[u]) tmp.erase(v);
        for (int v : tmp) {
            Q.emplace(v);
            nodes.erase(v);
            result.emplace_back(v);
        }
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for (int i = 0; i < n; ++i) nodes.emplace(i);
    vector<vector<int>> components;
    for (int i = 0; i < n; ++i) {
        if (!nodes.count(i)) continue;
        vector<int> ans = solve(i);
        components.emplace_back(ans);
    }
    cout << components.size() << "\n";
    for (auto v : components) {
        cout << v.size();
        for (auto e : v) cout << " " << e + 1;
        cout << "\n";
    }
    return 0;
}
