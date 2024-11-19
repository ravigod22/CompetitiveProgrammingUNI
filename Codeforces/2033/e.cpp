#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        x--;
        G[i].emplace_back(x);
    }
    vector<int> color(n, 0);
    int cnt = 0;
    auto dfs = [&] (auto self, int u) -> void {
        color[u] = 1;
        cnt++;
        for (int v : G[u]) {
            if (color[v] == 2) continue;
            else if (color[v] == 1) {
                return;
            }
            else self(self, v);
        }
        color[u] = 2;
    };
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 2) continue;
        cnt = 0;
        dfs(dfs, i);
        ans += (cnt - 1) / 2;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


