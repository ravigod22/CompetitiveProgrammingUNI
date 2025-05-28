#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 1e5 + 5;
vector<pair<int, int>> G[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b; cin >> n >> a >> b;
        a--, b--;
        for (int i = 1; i < n; ++i) {
            int u, v, w; cin >> u >> v >> w;
            u--, v--;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        vector<int> B(n, -1), A(n, -1);
        B[b] = 0;
        auto dfs = [&] (auto& self, int u, int p = -1) -> void {
            for (auto [v, w] : G[u]) {
                if (v == p) continue;
                B[v] = w ^ B[u];
                self(self, v, u);
            }
        };
        dfs(dfs, b);
        A[a] = 0;
        auto dfs1 = [&] (auto& self, int u, int p = -1) -> void {
            for (auto [v, w] : G[u]) {
                if (v == p or v == b) continue;
                A[v] = w ^ A[u];
                self(self, v, u);
            }
        };
        dfs1(dfs, a);
        B[b] = -1;
        set<int> teleport;
        for (int e : B) if (e != -1) teleport.insert(e);
        bool can = false;
        for (int i = 0; i < n; ++i) {
            if (A[i] == -1) continue;
            if (teleport.count(A[i])) can = true;
        }
        cout << (can ? "YES" : "NO") << "\n";
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    return 0;
}
