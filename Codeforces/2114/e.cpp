#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int N = 2e5 + 5;
int n;
int a[N];
i64 dp[N][2];
vector<int> G[N];

void dfs(int u, int p = -1) {
    for (int v : G[u]) {
        if (v == p) continue;
        dp[v][1] = max(0LL + a[v], 0LL + a[v] - dp[u][0]);
        dp[v][0] = min(0LL + a[v], 0LL + a[v] - dp[u][1]);
        dfs(v, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // min -> 0, max -> 1
    dp[0][1] = dp[0][0] = a[0];
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout << dp[i][1] << " \n"[i + 1 == n];
    }
    for (int i = 0; i < n; ++i) {
        G[i].clear();
    }
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


