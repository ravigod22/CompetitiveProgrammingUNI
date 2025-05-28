#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
vector<int> G[maxn];
vector<int> can[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> color(n, 0);
    auto dfs = [&] (auto& self, int u, int p) -> void {
        for (int v : G[u]) {
            if (v == p) continue;
            color[v] = 1 ^ color[u];
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);
    vector<int> one, zero;
    for (int i = 0; i < n; ++i) {
        if (color[i]) one.push_back(i);
        else zero.push_back(i);
    }
    set<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        vector<int> aux;
        if (color[i]) aux = zero;
        else aux = one;
        for (int e : aux) {
            bool can = false;
            for (int neigh : G[i]) {
                if (neigh == e) can = true;
            }
            if (can) continue;
            int x = i, y = e;
            if (x > y) swap(x, y);
            edges.emplace(x, y);
        }
    }
    bool turn;
    if (edges.size() & 1) {
        cout << "First" << endl;
        turn = true;
    }
    else {
        cout << "Second" << endl;
        turn = false;
    }
    while (true) {
        if (turn) {
            auto x = *edges.begin();
            edges.erase(edges.begin());
            cout << ++x.first << " " << ++x.second << endl; 
        }
        else {
            int a, b; cin >> a >> b;
            if (a > b) swap(a, b);
            if (a == -1 && b == -1) return 0;
            a--, b--;
            edges.erase({a, b});
        }
        turn ^= 1;
    }
    return 0;
}
