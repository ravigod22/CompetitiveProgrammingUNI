#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int mod = 998244353;
const int maxn = 3e5 + 5;
vector<int> G[maxn];

int add(int a, int b) {
    return (a + b) % mod;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u; cin >> u;
        u--;
        G[u].emplace_back(i);
    }
    vector<int> depth(n, 0);
    auto dfs = [&] (auto& self, int u, int p = -1) -> void {
        for (int v : G[u]) {
            if (v == p) continue;
            depth[v] = 1 + depth[u];
            self(self, v, u);
        }
    };
    dfs(dfs, 0);
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; ++i) {
        v[depth[i]].push_back(i);
    }
    vector<int> level(n + 1, 0);
    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; --i) {
        int sum = 0;
        for (int x : v[i]) {
            dp[x] = add(dp[x], level[i + 1]);
            if (i) {
                for (int y : G[x]) {
                    dp[x] = add(dp[x], mod - dp[y]);
                }
            }
            sum = add(sum, dp[x]);
        }
        level[i] = sum;
    }
    cout << dp[0] << "\n";
    for (int i = 0; i < n; ++i) G[i].clear();
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


